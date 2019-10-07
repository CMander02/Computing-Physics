#include"RandomJS.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
using namespace randomjs;
#define PI 3.1415926535

double StrangeFunction(double x)
{
	if (x <= -1 || x >= 2)
	{
		std::cout << "x is out of bound!" << endl;
		return 0;
	}
	else
	{
		return 1.0 / 2 / PI * pow(2 - x, -5 / 6.0) * pow(x + 1, -1.0/6);
	}
}

double f(double x)
{
	if (x <= -1 || x >= 2)
	{
		std::cout << "x is out of bound!" << endl;
		return 0;
	}
	else
	{
		return 3*PI / 2 / sqrt(2 - x) / sqrt(x + 1);
	}
}

bool getX(double &x)
{
	x = (1 - cos(PI*RandomSchrage())*3.0) / 2.0;
	return RandomFibonacci()*f(x) < StrangeFunction(x);
}

int main()
{
	ofstream out(".//rand.txt");
	double temp;
	clock_t startTime, endTime;
	startTime = clock();
	for (int i = 1; i < 1000000;)
	{
		if (getX(temp))
		{
			out << setprecision(10) << temp << endl;
			i++;
		}
	}
	endTime = clock();
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out.close();

	
	system("pause");
}