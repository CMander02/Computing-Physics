#include"RandomJS.h"
#include<iostream>
#include<fstream>
#include <iomanip>//目的为高精度输出

using namespace std;
using namespace randomjs;//使用自己random库的命名空间

int main()
{
	double x, y, z;
	ofstream output(".\\BallSurface.txt");//windows系统下用双斜杠
	clock_t startTime, endTime;
	startTime = clock();
	for (int i = 0; i < 10000;)
	{
		//因为int值只有离散的9位，输出10位足够分析
		//if (BallSurfaceMarsaglia(x, y, z)) 
		//{
		//	
		//	i++;
		//}
		BallSurface(x, y, z);
		output << '{' << setprecision(10) << x << ',' << y << ',' << z << '}' << ',';
		i++;
	}
	endTime = clock();//计时结束
	output.close();
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
}