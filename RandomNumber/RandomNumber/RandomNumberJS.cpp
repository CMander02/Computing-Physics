#include<ctime>
#include<vector>//����������Fibonacci�����е�Ԥ����
#include "RandomNumberJS.h"
namespace randomjs //��ֹ�պ�����������ͻ
{
	//*********************���²��ֶ��������������***************************
	constexpr int m = 2147483647;
	constexpr int a = 16807;
	constexpr int b = 0;
	constexpr int q = m / a;
	constexpr int r = m % a;
	static int seed = int(time(NULL)) % m > 0 ? int(time(NULL)) % m : int(time(NULL)) % m + m;

	int RandomSchrageInt()//Schrage�㷨��int�汾
	{
		int temp = a * (seed%q) - r * (seed / q);//ͨ����ʽʹ��������ÿһ���ȫ
		seed = temp > 0 ? temp : temp + m;
		return seed;
	}

	double RandomSchrage()
	{
		int temp = a * (seed%q) - r * (seed / q);//ͨ����ʽʹ��������ÿһ���ȫ
		seed = temp >= 0 ? temp : temp + m;
		return seed / double(m);
	}


	constexpr int p_fib = 97;
	constexpr int q_fib = 33;
	constexpr int size = p_fib > q_fib ? p_fib : q_fib;
	int arr[size];
	static int head = 0, tail = (p_fib - q_fib) % size;
	static bool init = false;

	double RandomFibonacci()
	{
		if (!init)//����Schrage�㷨�����г�ʼ��
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = RandomSchrageInt();
			}
			init = true;
		}
		int temp = arr[head] ^ arr[tail] % m;
		temp = temp < 0 ? temp + m : temp;
		arr[head] = temp;
		head = (head + 1) % size;
		tail = (tail + 1) % size;
		return temp / double(m);
	}

	double RandomGauss(double mu, double sigma)
	{
		return sigma * sqrt(-2 * log(RandomSchrage()))*CosRandom() + mu;
	}

	void SetSeed(int in)
	{
		seed = in;
	}

	//*********************���ϲ��ֶ��������������***************************
}