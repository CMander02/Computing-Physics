#include"RandomJS.h"
#include<iostream>
#include<fstream>
#include <iomanip>//Ŀ��Ϊ�߾������

using namespace std;
using namespace randomjs;//ʹ���Լ�random��������ռ�

int main()
{
	double x, y, z;
	ofstream output(".\\BallSurface.txt");//windowsϵͳ����˫б��
	clock_t startTime, endTime;
	startTime = clock();
	for (int i = 0; i < 10000;)
	{
		//��Ϊintֵֻ����ɢ��9λ�����10λ�㹻����
		//if (BallSurfaceMarsaglia(x, y, z)) 
		//{
		//	
		//	i++;
		//}
		BallSurface(x, y, z);
		output << '{' << setprecision(10) << x << ',' << y << ',' << z << '}' << ',';
		i++;
	}
	endTime = clock();//��ʱ����
	output.close();
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
}