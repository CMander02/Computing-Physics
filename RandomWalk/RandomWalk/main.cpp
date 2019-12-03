#include"Particle.h"

int main()
{
	Particle<3> p;
	for (int i = 0; i < 100; i++)
	{
		p.move_random();
		p.get_position().print();
	}
	system("pause");
}