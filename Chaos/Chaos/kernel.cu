
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<cmath>
#include<iostream>
#include <stdio.h>
#include<iomanip>
#include<fstream>

using namespace std;

#define precision 1E-8
#define PI 3.141592653589793238462643383
#define divide (8192)
#define saving 8192

#define lambdamax 1.5
#define dlambda (double(lambdamax)/divide)

const int times = 1000000;

__global__ void kernel(double *dev_arr)//��ÿһ���߳̽��м���
{
	int offset = blockDim.x*blockIdx.x + threadIdx.x;//λ���ƶ�
	double thread_lambda = offset * dlambda;

	int start = offset * saving;

	for (int i = 0; i < times; i++)
	{
		dev_arr[start + (i) % saving] = thread_lambda * sin(PI * dev_arr[start + (i - 1) % saving]);
	}

}

double arr[divide*saving];//ÿһ���̻߳���һ����СΪ1024������buffer

int main()
{	

	ofstream out("C:\\Users\\10069\\Desktop\\Sinx.txt");
	double *dev_arr;

	cudaMalloc((void**)&dev_arr, sizeof(double)*divide*saving);

	for (int i = 0; i < divide*saving; i++)
	{
		arr[i] = rand()-(RAND_MAX/2);
	}
		
	cudaMemcpy(dev_arr,arr, sizeof(double)*divide*saving, cudaMemcpyHostToDevice);
	

	int blocksize = 512;

	kernel<<<divide / blocksize, blocksize >>>(dev_arr);

	cudaMemcpy(arr, dev_arr, sizeof(double)*divide*saving, cudaMemcpyDeviceToHost);

	double result = 0;
	out << setprecision(12);
	for (int i = 0; i < divide*saving; i++)
	{
		out << arr[i] << ' ';
	}

	cudaFree(dev_arr);
	out.close();

	system("pause");
}

