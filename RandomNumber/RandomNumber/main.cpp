#include"RandomDB.h"
#include<iostream>
#include<fstream>
#include <iomanip>//Ŀ��Ϊ�߾������

using namespace std;
using namespace randomdb;
int main()
{
	clock_t startTime, endTime;
	startTime = clock();
	ofstream output(".\\Rand.txt");
	for (int i = 0; i < 100000; i++)
	{
		//��Ϊintֵֻ����ɢ��9λ�����10λ�㹻����
		output << setprecision(10) << RandomSchrage() << endl;
	}
	output.close();
	endTime = clock();//��ʱ����
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
}