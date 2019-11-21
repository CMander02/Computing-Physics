#ifndef SAMPLINGJS
#define SAMPLINGJS

namespace randomjs 
{
	void BallSurface(double &x, double&y, double&z, double func() = RandomSchrage);
	bool BallSurfaceMarsaglia(double &x, double &y, double &z);

	double DirectSampling(double inversedFunc(double));//ֱ�ӳ�����������Ҫ����Ŀ��ֲ����ۻ��ֲ������ķ�����

	double RejectionSampling(double func(double), double sample(double), double compare(double));//�򵥷ֲ��ı任��������ѡ������������ֱ�Ϊ����������ֲ��������ȽϺ������ȽϺ����ĳ���
	
}




#endif // !SAMPLINGJS

