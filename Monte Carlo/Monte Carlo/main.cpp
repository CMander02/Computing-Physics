#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include"Bound.h"

using namespace std;

double MonteCarloIntegrate(double func(std::vector<double>&), std::initializer_list<Bound> list, int cycle=1e5);//参数分别为传入的函数，边界，循环次数

double f(vector<double> &vec)//这样的写法比较丑陋，但目前还没有想到很好的解决办法，主要是可变长参数传递会难以生成随机数
{
	return sqrt(vec[0] + sqrt(vec[0]));
}

double g(vector<double> &vec)//使用vector传参是不得已的，希望能有更加自然的写法
{
	double temp = 6;
	for (auto c : vec)
	{
		temp -= c * c;
	}
	return temp;
}


int main()
{
	ofstream out(".//result2.txt");
	clock_t startTime, endTime;
	startTime = clock();
	cout << setprecision(9);//设置输出精度

	cout << MonteCarloIntegrate(f, { Bound(0, 2) },10e4) << endl;

	cout << MonteCarloIntegrate(g, { Bound(0,0.9),Bound(0,0.8),Bound(0,0.9),Bound(0,2),Bound(0,1.3) },1e4) << endl;

	endTime = clock();
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out.close();


	system("pause");
}