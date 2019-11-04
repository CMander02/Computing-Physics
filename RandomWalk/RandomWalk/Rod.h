#pragma once
#include"Particle.h"

template<unsigned dimension>
class Rod
{
public:
	Rod() = default;
	~Rod() = default;//Vector写得好点这里就可以省事

	void move()
	{
		auto tempa = a, tempb = b;

	}

private:

	Particle<dimension> a;
	Particle<dimension> b;

	const Vector<dimension> vec = b - a;
	
};

