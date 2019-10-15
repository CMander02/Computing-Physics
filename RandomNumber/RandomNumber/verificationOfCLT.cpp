#include"RandomJS.h"
#include<iostream>
#include<fstream>
#include <iomanip>//目的为高精度输出
#include<cmath>

using namespace std;
using namespace randomjs;//使用自己random库的命名空间

int main()
{
	ofstream out2("C:\\Users\\10069\\Desktop\\result2.txt");
	ofstream out5("C:\\Users\\10069\\Desktop\\result5.txt");
	ofstream out10("C:\\Users\\10069\\Desktop\\result10.txt");
	clock_t startTime, endTime;
	startTime = clock();

	out2 << setprecision(10);

	for (int i = 0; i < 1000000; i++)
	{
		double x1 = RandomFibonacci() + 3;
		double x2 = asin(RandomSchrage() * 2 - 1)/5;
		double x3 = acos(RandomFibonacci() * 2 - 1) / 5+3;
		double x4 = acos(RandomFibonacci() * 2 - 1) / 2 + 2;
		double x5 = -0.1*log(RandomSchrage());
		double x6 = RandomFibonacci() + 6;
		double x7 = asin(RandomSchrage() * 2 - 1) / 5+10;
		double x8 = acos(RandomFibonacci() * 2 - 1) / 5 + 3+2;
		double x9 = x4 = acos(RandomFibonacci() * 2 - 1) *2 + 2;
		double x0 = 0.2*log(RandomSchrage());
		out2 << x1 + x2 << ' ';
		out5 << x1 + x2 + x3 + x4 + x5 << endl;
		double temp = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x0;
			out10 << temp << endl;
	}

	out2.close();
	out5.close();
	out10.close();
	endTime = clock();//计时结束
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
}