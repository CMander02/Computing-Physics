//#include"RandomJS.h"
//#include<iostream>
//#include<fstream>
//#include <iomanip>//目的为高精度输出
//
//#define PI 3.1415926535
//
//#define LENGTH (3013-2900+2)
//int numberOfParticles[LENGTH];//该数组第一个元素（下标为0）储存总粒子数量
//double frequence[LENGTH - 1];
//double max = 0;//记录频率的最大值，便于之后的舍选法使用
//
//using namespace std;
//using namespace randomjs;//使用自己random库的命名空间
//
//double inverse(double in)
//{
//	int i = 0;
//	while (in > frequence[i])
//	{
//		i++;
//	}
//	return i + 2900;
//}
//
//int main()
//{
//	clock_t startTime, endTime;
//	startTime = clock();
//	ifstream in("C:\\Users\\10069\\Desktop\\data.TXT");
//	ofstream direct_out(".\\direct.txt");
//	ofstream rejection_out(".\\rejection.txt");
//	int energy;
//	int i = 1;
//	while (in >> energy)
//	{
//		in >> numberOfParticles[i++];
//	}
//	for (int i = 1; i < LENGTH; i++)
//	{
//		numberOfParticles[0] += numberOfParticles[i];
//	}
//
//	//以下是为了建立频率和粒子数目的函数
//	frequence[0] = numberOfParticles[1] / (double)(numberOfParticles[0]);
//	for (int i = 1; i < LENGTH - 1; i++)
//	{
//		frequence[i] = frequence[i - 1] + numberOfParticles[i + 1] / double(numberOfParticles[0]);
//		if (frequence[i] > max)
//		{
//			max = frequence[i];
//		}
//	}
//
//	for (int i = 0; i < 1000000; i++)
//	{
//		direct_out << DirectSampling(inverse) + (RandomFibonacci() - 0.5) * 4 << endl;
//	}
//
//	for (int i = 0; i < 1000000; i++)
//	{
//		rejection_out << RejectionSampling([](double x)->double {return double(numberOfParticles[int(x) - 2900 + 1]) / numberOfParticles[0]; }, [](double x)->double {return x * (LENGTH - 1) + 2900; }, [](double x)-> double { return double(max); }) << endl;
//	}
//
//	direct_out.close();
//	rejection_out.close();
//	endTime = clock();//计时结束
//	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
//	getchar();
//}