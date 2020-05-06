#include"Particle.h"
#include<iostream>
#include<fstream>

using namespace std;

#define BATCH_SIZE 10000

const int dim = 1;
const int epoch = 1000000;

Particle<dim> p[BATCH_SIZE];
int main()
{
	ofstream fdemon("C:\\Users\\10069\\Desktop\\demon_10000_50_1_l.txt");
	ofstream fenerg("C:\\Users\\10069\\Desktop\\energ_10000_50_1_l.txt");

	double demon = 0;

	double total = 0;
	for (int i = 0; i < BATCH_SIZE; i++)
	{
		p[i].set_kinetic_energy(50);//初始能量的设定
	}

	for (int i = 0; i < epoch;)
	{
		int index = RandomSchrageInt() % BATCH_SIZE;//从集合中随机选取一个粒子进行速度的涨落
		auto temp = p[index];//保存粒子当前的状态
		temp.accelerate(RandomVectorOnBall<dim>(1));//对粒子进行一次随机的加速
		if (p[index].kinetic_energy()+demon<temp.kinetic_energy())//如果超过了demon能得允许则跳过
		{
			continue;
		}
		else
		{
			demon += p[index].kinetic_energy() - temp.kinetic_energy();
			p[index] = temp;
			i++;
			if (i>1000)
			{
				fdemon << demon << ' ';
			}
			if (i == epoch - 100)//已经达到平衡态之后
			{
				for (int j = 0; j < BATCH_SIZE; j++)
				{
						fenerg << p[j].kinetic_energy() << ' ';
				}
			}
		}
	}


	system("pause");
}