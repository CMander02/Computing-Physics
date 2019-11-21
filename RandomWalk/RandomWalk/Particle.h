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
class Particle
{
public:
	Particle() = default;//���ṩ�κι��캯��������ϵͳ�ϳ�

	Particle(std::initializer_list<double> list) :coordinates(list) {}
	Particle(Vector<dimension> &in_vec):coordinates(in_vec) {}
	Particle(Vector<dimension> &&in_vec) :coordinates(std::move(in_vec)) {}

	Particle& operator= (const Particle& p) { step = p.step; coordinates = p.coordinates; return *this; }
	Particle& operator= (const Particle&& p) { step = p.step; coordinates = std::move(p.coordinates); return *this; }


	Particle(const Particle& p) :step(p.step), coordinates(p.coordinates) {}
	Particle(Particle&& p) :step(p.step), coordinates(std::move(p.coordinates)) {}

	~Particle() = default;

	Particle& move(MOVE_TYPE type = ON_GRID)//δ���м̳д���Ŀ���
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
			coordinates += step * RandomVectorOnBall<dimension>()*(2 * RandomSchrage() - 1);
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
			coordinates += l * RandomVectorOnBall<dimension>()*(2 * RandomSchrage() - 1);
			break;
		}
		return *this;

	}
	//virtual void move(Field<dimension>&);

	double operator[](int i)
	{
		return coordinates[i];
	}

	Vector<dimension>& get_position()
	{
		return coordinates;
	}

	Vector<dimension> get_position() const
	{
		return coordinates;
	}

	bool operator==(const Particle& r)
	{
		return coordinates == r.coordinates;
	}

private:
	

	double step = 1;

	Vector<dimension> coordinates;
	
};
