#include"RandomJS.h"
#include<initializer_list>
#include<list>
#include<vector>
#include"Bound.h"
using namespace randomjs;
#include<cmath>
#define PI 3.1415926535




//此处用C++语法多一点是希望写出真正有复用价值的代码，并没有调用C++的库来实现核心功能
double MonteCarloIntegrate(double func(std::vector<double>&), std::initializer_list<Bound> list, int cycle)
{
	int dim = list.size();
	double volume = 1;
	for (auto c:list)
	{
		volume *= (c.upper - c.lower);
	}

	double result = 0;
	int N = cycle;
	for (int i = 0; i < N; i++)
	{
		std::vector<double> xs;
		for (int i = 0; i < dim; i++)
		{
			auto ptr = list.begin() + i;
			xs.push_back(RandomSchrage()*(ptr->upper - ptr->lower));
		}
		result += func(xs);
	}
	return result * volume / N;
}

