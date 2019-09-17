#include"RandomDB.h"
#include<iostream>
#include<fstream>
#include <iomanip>//目的为高精度输出

using namespace std;
using namespace randomdb;
int main()
{
	clock_t startTime, endTime;
	startTime = clock();
	ofstream output(".\\Rand.txt");
	for (int i = 0; i < 100000; i++)
	{
		//因为int值只有离散的9位，输出10位足够分析
		output << setprecision(10) << RandomSchrage() << endl;
	}
	output.close();
	endTime = clock();//计时结束
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
}