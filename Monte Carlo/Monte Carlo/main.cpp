#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include"Bound.h"

using namespace std;

double MonteCarloIntegrate(double func(std::vector<double>&), std::initializer_list<Bound> list, int cycle=1e5);//�����ֱ�Ϊ����ĺ������߽磬ѭ������

double f(vector<double> &vec)//������д���Ƚϳ�ª����Ŀǰ��û���뵽�ܺõĽ���취����Ҫ�ǿɱ䳤�������ݻ��������������
{
	return sqrt(vec[0] + sqrt(vec[0]));
}

double g(vector<double> &vec)//ʹ��vector�����ǲ����ѵģ�ϣ�����и�����Ȼ��д��
{
	double temp = 6;
	for (auto c : vec)
	{
		temp -= c * c;
	}
	return temp;
}


int main()
{
	ofstream out(".//result2.txt");
	clock_t startTime, endTime;
	startTime = clock();
	cout << setprecision(9);//�����������

	cout << MonteCarloIntegrate(f, { Bound(0, 2) },10e4) << endl;

	cout << MonteCarloIntegrate(g, { Bound(0,0.9),Bound(0,0.8),Bound(0,0.9),Bound(0,2),Bound(0,1.3) },1e4) << endl;

	endTime = clock();
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out.close();


	system("pause");
}