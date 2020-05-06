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
		p[i].set_kinetic_energy(50);//��ʼ�������趨
	}

	for (int i = 0; i < epoch;)
	{
		int index = RandomSchrageInt() % BATCH_SIZE;//�Ӽ��������ѡȡһ�����ӽ����ٶȵ�����
		auto temp = p[index];//�������ӵ�ǰ��״̬
		temp.accelerate(RandomVectorOnBall<dim>(1));//�����ӽ���һ������ļ���
		if (p[index].kinetic_energy()+demon<temp.kinetic_energy())//���������demon�ܵ�����������
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
			if (i == epoch - 100)//�Ѿ��ﵽƽ��̬֮��
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