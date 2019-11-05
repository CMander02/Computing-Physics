#pragma once
#include"Particle.h"


template<unsigned dimension>
class Rod
{
public:
	Rod(double len=1) :length(len) {}
	~Rod() = default;//Vector写得好点这里就可以省事

	void move(MOVE_TYPE type=CONTINUOUS_DIRECTION)
	{

		Particle<dimension> tempa = center.get_position() + 1.0 / 2 * length*direction;
		Particle<dimension> tempb = center.get_position() - 1.0 / 2 * length*direction;

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

	Particle<dimension> center;
	Vector<dimension> direction;

	double length = 3;
	
};

