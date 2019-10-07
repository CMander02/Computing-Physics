//第三题：尝试抽样一个很奇怪的函数
#include<cstdlib>
#include<iostream>
#include<cmath>
#include"RandomJS.h"
using namespace std;
using namespace randomjs;
#define PI 3.1415926535
double StrangeFunction(double x)
{
	if (x<=-1||x>=2)
	{
		std::cout << "x is out of bound!" << endl;
		return 0;
	}
	else
	{
		return 1.0 / 2 / PI / pow(2 - x, 5 / 6.0) / pow(x + 1, 1 / 6.0);
	}
}

