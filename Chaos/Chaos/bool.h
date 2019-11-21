#ifndef __BOOK_H__
#define __BOOK_H__
#include <stdio.h>
#include <stdlib.h>         // �Լ��ӵ�
#include "cuda_runtime.h"   // �Լ��ӵ�
#include "device_launch_parameters.h"


static void HandleError(cudaError_t err, const char *file, int line)//���屨������ͨ������ķ���ֵ���ļ������к�����ʾ��Ϣ
{
	if (err != cudaSuccess)
	{
		printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
		exit(EXIT_FAILURE);
	}
}
#define HANDLE_ERROR( err ) (HandleError( err, __FILE__, __LINE__ ))// ����������װΪ�꣬�Զ������ļ������к�

#define HANDLE_NULL( a )/* ��ָ�뱨������������mallocʧ��ʱ���� */              \
{                                                                             \
    if (a == NULL)                                                            \
    {                                                                         \
        printf( "Host memory failed in %s at line %d\n", __FILE__, __LINE__ );\
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}

template< typename T >// ���ͽ�����ȫ�鶼û�õ�����
void swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

void* big_random_block(int size)//������������������飬�޷����ַ���
{
	unsigned char *data = (unsigned char*)malloc(size);
	HANDLE_NULL(data);
	for (int i = 0; i < size; data[i] = rand(), i++);
	return data;
}

int* big_random_block_int(int size)//������������������飬����
{
	int *data = (int*)malloc(size * sizeof(int));
	HANDLE_NULL(data);
	for (int i = 0; i < size; data[i] = rand(), i++);
	return data;
}

// �����豸����
__device__ unsigned char value(float n1, float n2, int hue)
{
	if (hue > 360)
		hue -= 360;
	else if (hue < 0)
		hue += 360;
	if (hue < 60)
		return (unsigned char)(255 * (n1 + (n2 - n1)*hue / 60));
	if (hue < 180)
		return (unsigned char)(255 * n2);
	if (hue < 240)
		return (unsigned char)(255 * (n1 + (n2 - n1)*(240 - hue) / 60));
	return (unsigned char)(255 * n1);
}

__global__ void float_to_color(unsigned char *optr, const float *outSrc)
{
	int x = threadIdx.x + blockIdx.x * blockDim.x;
	int y = threadIdx.y + blockIdx.y * blockDim.y;
	int offset = x + y * blockDim.x * gridDim.x;

	float l = outSrc[offset];
	float s = 1;
	int h = (180 + (int)(360.0f * outSrc[offset])) % 360;
	float m1, m2;

	if (l <= 0.5f)
		m2 = l * (1 + s);
	else
		m2 = l + s - l * s;
	m1 = 2 * l - m2;

	optr[offset * 4 + 0] = value(m1, m2, h + 120);
	optr[offset * 4 + 1] = value(m1, m2, h);
	optr[offset * 4 + 2] = value(m1, m2, h - 120);
	optr[offset * 4 + 3] = 255;
}

__global__ void float_to_color(uchar4 *optr, const float *outSrc)
{
	int x = threadIdx.x + blockIdx.x * blockDim.x;
	int y = threadIdx.y + blockIdx.y * blockDim.y;
	int offset = x + y * blockDim.x * gridDim.x;

	float l = outSrc[offset];
	float s = 1;
	int h = (180 + (int)(360.0f * outSrc[offset])) % 360;
	float m1, m2;

	if (l <= 0.5f)
		m2 = l * (1 + s);
	else
		m2 = l + s - l * s;
	m1 = 2 * l - m2;

	optr[offset].x = value(m1, m2, h + 120);
	optr[offset].y = value(m1, m2, h);
	optr[offset].z = value(m1, m2, h - 120);
	optr[offset].w = 255;
}

// �й��̵߳�����
#if _WIN32
	//Windows threads.
#include <windows.h>

typedef HANDLE CUTThread;// ͳһ��װ
typedef unsigned (WINAPI *CUT_THREADROUTINE)(void *);

#define CUT_THREADPROC unsigned WINAPI
#define  CUT_THREADEND return 0

#else
	//POSIX threads.
#include <pthread.h>

typedef pthread_t CUTThread;
typedef void *(*CUT_THREADROUTINE)(void *);

#define CUT_THREADPROC void
#define  CUT_THREADEND
#endif

// �̵߳Ĵ��죬���߳̽��������߳����ٺͶ��̵߳ȴ�
CUTThread start_thread(CUT_THREADROUTINE, void *data);
void end_thread(CUTThread thread);
void destroy_thread(CUTThread thread);
void wait_for_threads(const CUTThread *threads, int num);

#if _WIN32
CUTThread start_thread(CUT_THREADROUTINE func, void *data)
{
	return CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, data, 0, NULL);
}

void end_thread(CUTThread thread)
{
	WaitForSingleObject(thread, INFINITE);
	CloseHandle(thread);
}

void destroy_thread(CUTThread thread)
{
	TerminateThread(thread, 0);
	CloseHandle(thread);
}

void wait_for_threads(const CUTThread * threads, int num) {
	WaitForMultipleObjects(num, threads, true, INFINITE);

	for (int i = 0; i < num; i++)
		CloseHandle(threads[i]);
}

#else
CUTThread start_thread(CUT_THREADROUTINE func, void * data)
{
	pthread_t thread;
	pthread_create(&thread, NULL, func, data);
	return thread;
}

void end_thread(CUTThread thread)
{
	pthread_join(thread, NULL);
}

void destroy_thread(CUTThread thread)
{
	pthread_cancel(thread);
}

void wait_for_threads(const CUTThread * threads, int num)
{
	for (int i = 0; i < num; i++)
		end_thread(threads[i]);
}
#endif

#endif  // __BOOK_H__