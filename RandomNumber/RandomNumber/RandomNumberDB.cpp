#include<ctime>
#include<vector>//用来保存在Fibonacci数列中的预先项
namespace randomdb //防止日后调库的命名冲突
{
	constexpr int m = 2147483647;
	constexpr int a = 16087;
	constexpr int b = 0;
	constexpr int q = m / a;
	constexpr int r = m % a;
	static int seed = int(time(NULL));
	
	int RandomSchrageInt()//Schrage算法的int版本
	{
		int temp = a * (seed%q) - r * (seed / q);//通过公式使得运算中每一项都安全
		seed = temp > 0 ? temp : temp + m;
		return seed;
	}

	double RandomSchrage()
	{
		int temp = a * (seed%q) - r * (seed / q);//通过公式使得运算中每一项都安全
		seed = temp > 0 ? temp : temp + m;
		return seed / double(m);
	}


	constexpr int p_fib = 20;
	constexpr int q_fib = 30;
	constexpr int size = p_fib > q_fib ? p_fib : q_fib;
	int arr[size];
	static int head = 0, tail = (p_fib - q_fib) % size;
	bool init = false;

	double RandomFibonacci() 
	{
		if (!init)//利用Schrage算法来进行初始化
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

	void SetSeed(int in)
	{
		seed = in;
	}
}