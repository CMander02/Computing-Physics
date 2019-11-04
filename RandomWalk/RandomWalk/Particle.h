#pragma once

#include"Field.h"
#include"RandomJS.h"
#include<initializer_list>
#include<iostream>
#include"Vector.h"
using namespace randomjs;

enum MOVE_TYPE
{
	ON_GRID, CONTINUOUS_DIRECTION, CONTINUOUS_DISTANCE, CONTINUOUS_ALL
};//�������͵������Լд�úͶ���ʦ�Ľ���һ������������⣬����Ҫ���κν���

template<unsigned dimension>
class Particle:public Vector<dimension>
{
	using Vector<dimension>::coordinates;
public:
	Particle() = default;//���ṩ�κι��캯��������ϵͳ�ϳ�

	Particle(std::initializer_list<double> list) :Vector<dimension>(list) {}
	virtual ~Particle() = default;

	virtual void move(MOVE_TYPE type = ON_GRID)//δ���м̳д���Ŀ���
	{
		double dis = 1.0 / dimension;
		int i = 0;
		double level = RandomFibonacci();//���ѡȡһ��ά�Ƚ�������
		double l = step * RandomSchrage();

		switch (type)
		{
		case ON_GRID:
			while (i*dis < level)
				i++;
			if (RandomSchrage() > 0.5)
			{
				coordinates[i - 1] += step;
			}
			else
			{
				coordinates[i - 1] -= step;
			}
			break;
		case CONTINUOUS_DIRECTION:
			*this += step * RandomVectorOnBall<dimension>()*(2 * RandomSchrage() - 1);
			break;
		case CONTINUOUS_DISTANCE:
			while (i*dis < level)
				i++;
			if (RandomSchrage() > 0.5)
			{
				coordinates[i - 1] += l;
			}
			else
			{
				coordinates[i - 1] -= l;
			}
			break;
		case CONTINUOUS_ALL:
			*this += l * RandomVectorOnBall<dimension>()*(2 * RandomSchrage() - 1);
			break;
		}

	}
	//virtual void move(Field<dimension>&);

	//double operator[](int i)
	//{
	//	return coordinates[i];
	//}

private:
	

	double step = 1;

	//Vector<dimension> coordinates;
	
};

