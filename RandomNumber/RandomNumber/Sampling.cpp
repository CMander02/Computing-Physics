#include<cmath>
#include"RandomNumberJS.h"

namespace randomjs {
	constexpr double PI = 3.1415926535;
	void BallSurface(double &theta, double&phi)//����дʵ�������൱��ª�ģ����������Ĵ����в�����������̵ķ�񡣵���Ϊ��
	{
		phi = RandomSchrage() * 2 * PI;
		theta = 2 * asin(2 * RandomSchrage()) + PI / 2;
	}
}