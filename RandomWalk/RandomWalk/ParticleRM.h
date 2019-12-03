#pragma once

#include"Field.h"
#include"RandomJS.h"
#include<initializer_list>
#include<iostream>
#include"Vector.hpp"
using namespace randomjs;

enum MOVE_TYPE
{
	ON_GRID, CONTINUOUS_DIRECTION, CONTINUOUS_DISTANCE, CONTINUOUS_ALL
};//�������͵������Լд�úͶ���ʦ�Ľ���һ������������⣬����Ҫ���κν���

template<unsigned dimension>
class ParticleRM //RM stands for random walk!
{
public:
	ParticleRM() = default;//���ṩ�κι��캯��������ϵͳ�ϳ�

	ParticleRM(std::initializer_list<double> list) :coordinates(list) {}
	ParticleRM(Vector<dimension> &in_vec):coordinates(in_vec) {}
	ParticleRM(Vector<dimension> &&in_vec) :coordinates(std::move(in_vec)) {}

	ParticleRM& operator= (const ParticleRM& p) { step = p.step; coordinates = p.coordinates; return *this; }
	ParticleRM& operator= (const ParticleRM&& p) { step = p.step; coordinates = std::move(p.coordinates); return *this; }


	ParticleRM(const ParticleRM& p) :step(p.step), coordinates(p.coordinates) {}
	ParticleRM(ParticleRM&& p) :step(p.step), coordinates(std::move(p.coordinates)) {}

	virtual ~ParticleRM() = default;

	ParticleRM& move(MOVE_TYPE type = ON_GRID)//δ���м̳д���Ŀ���
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
			coordinates += RandomVectorOnBall<dimension>(step);
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
			coordinates +=  RandomVectorOnBall<dimension>(l);
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

	bool operator==(const ParticleRM& r)
	{
		return coordinates == r.coordinates;
	}

private:

	double step = 1;

	Vector<dimension> coordinates;
	
};
