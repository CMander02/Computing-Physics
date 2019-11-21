#ifndef SAMPLINGJS
#define SAMPLINGJS

namespace randomjs 
{
	void BallSurface(double &x, double&y, double&z, double func() = RandomSchrage);
	bool BallSurfaceMarsaglia(double &x, double &y, double &z);

	double DirectSampling(double inversedFunc(double));//直接抽样方法，需要输入目标分布的累积分布函数的反函数

	double RejectionSampling(double func(double), double sample(double), double compare(double));//简单分布的变换抽样和舍选法抽样，输入分别为待抽变量，分布函数，比较函数，比较函数的抽样
	
}




#endif // !SAMPLINGJS

