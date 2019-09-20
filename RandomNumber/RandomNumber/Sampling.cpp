#include<cmath>
#include"RandomNumberJS.h"

namespace randomjs {
	constexpr double PI = 3.1415926535;
	void BallSurface(double &theta, double&phi)//这样写实际上是相当丑陋的，在面向对象的代码中插入了面向过程的风格。但是为了
	{
		phi = RandomSchrage() * 2 * PI;
		theta = 2 * asin(2 * RandomSchrage()) + PI / 2;
	}
}