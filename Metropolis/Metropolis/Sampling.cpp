#include<cmath>
#include"RandomNumberJS.h"
#include "SamplingJS.h"

namespace randomjs {
	constexpr double PI = 3.1415926535;
	void BallSurface(double &x, double&y, double&z, double func())
	{
		double phi = func() * 2 * PI;
		double theta = acos(1 - 2 * func());
		x = sin(theta)*cos(phi);
		y = sin(theta)*sin(phi);
		z = cos(theta);
	}

	bool BallSurfaceMarsaglia(double &x,double &y,double &z) //通过返回值来判断抽样是否成功！
	{
		double u = 2 * RandomSchrage() - 1, v = 2 * RandomFibonacci() - 1;
		if (u*u + v * v > 1)
		{
			return false;
		}
		double temp = sqrt(1 - u * u - v * v);
		x = 2 * u*temp;
		y = 2 * v*temp;
		z = 1 - 2 * (u*u + v * v);
		return true;
	}
	double DirectSampling(double inversedFunc(double))
	{
		return inversedFunc(RandomSchrage());
	}
	double RejectionSampling(double func(double), double sample(double), double compare(double))
	{
		double x = sample(RandomSchrage());
		while (compare(x)*RandomFibonacci() > func(x))
		{
			x = sample(RandomSchrage());
		}
		return x;
	}
}