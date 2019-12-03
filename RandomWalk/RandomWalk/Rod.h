#pragma once
#include"ParticleRM.h"


template<unsigned dimension>
class Rod
{
public:
	Rod(double len=1) :length(len) {}
	~Rod() = default;//Vectorд�úõ�����Ϳ���ʡ��

	void move(MOVE_TYPE type=CONTINUOUS_DIRECTION)
	{

		ParticleRM<dimension> tempa = center.get_position() + 1.0 / 2 * length*direction;
		ParticleRM<dimension> tempb = center.get_position() - 1.0 / 2 * length*direction;

		tempa.move(type);
		tempb.move(type);

		direction += tempa.get_position()-(center.get_position() + 1.0 / 2 * length*direction);
		direction -= tempb.get_position()-(center.get_position() - 1.0 / 2 * length*direction);


		center.get_position() = (tempa.get_position() + tempb.get_position()) / 2;

		direction /= direction.length();
		direction *= length;

	}

	Vector<dimension> get_direction()
	{
		return direction / length;
	}

//private:

	ParticleRM<dimension> center;
	Vector<dimension> direction;

	double length = 3;
	
};

