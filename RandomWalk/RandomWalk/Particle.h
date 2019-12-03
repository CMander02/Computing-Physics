#ifndef PARTICLE
#define PARTICLE

#include"ParticleRM.h"

template<unsigned int dimension>
class Particle :public ParticleRM<dimension>
{
public:

	Particle() = default;
	Particle(const Vector<dimension>&c, const Vector<dimension>&v) :ParticleRM(c), velocity(v) {}
	Particle(const Vector<dimension>&&c, const Vector<dimension>&v)noexcept :ParticleRM(std::move(c)), velocity(v) {}
	Particle(const Vector<dimension>&c, const Vector<dimension>&&v) noexcept :ParticleRM(c), velocity(std::move(v)) {}
	Particle(const Vector<dimension>&&c, const Vector<dimension>&&v) noexcept :ParticleRM(std::move(c)), velocity(std::move(v)) {}
	Particle(const Particle& p) :ParticleRM<dimension>(p), mass(p.mass), velocity(p.velocity) {  }
	Particle(Particle&& p) { this->step = p.step, this->coordinates = std::move(p.coordinates); }

	Particle& operator= (const Particle& p);
	Particle& operator= (const Particle&& p);
	Particle& move(double tick = 1.0);
	Particle<dimension>& move_random(MOVE_TYPE type = ON_GRID);

	Particle<dimension>& accelerate(const Vector<dimension>& delta_v);

	Particle& set_velocity(const Vector<dimension> &v);
	Vector<dimension>& get_velocity();
	Vector<dimension> get_velocity() const;


	Particle& set_mass(double m);
	Particle& set_kinetic_energy(double e);

	double kinetic_energy();



private:

	Vector<dimension> velocity;
	double mass = 1.0;

};

#endif // !PARTICLE

template<unsigned int dimension>
Particle<dimension>& Particle<dimension>::operator=(const Particle & p)
{
	this->step = p.step;
	this->coordinates = p.coordinates;
	mass = p.mass;
	velocity = p.velocity;
	return *this;
}

template<unsigned int dimension>
Particle<dimension>& Particle<dimension>::operator=(const Particle && p)
{
	this->step = p.step;
	this->mass = p.mass;
	this->velocity = std::move(p.velocity);
	this->coordinates = std::move(p.coordinates); return *this;
}

template<unsigned int dimension>
Particle<dimension>& Particle<dimension>::move(double tick)
{
	this->get_position() += velocity * tick;
	return *this;
}

template<unsigned int dimension>
Particle<dimension>& Particle<dimension>::move_random(MOVE_TYPE type)
{
	ParticleRM<dimension>::move(type);
	return *this;
}

template<unsigned int dimension>
inline Particle<dimension>& Particle<dimension>::accelerate(const Vector<dimension>& delta_v)
{
	this->velocity += delta_v;
	return *this;
}

template<unsigned int dimension>
Particle<dimension>& Particle<dimension>::set_velocity(const Vector<dimension>& v)
{
	velocity = v;
	return *this;
}

template<unsigned int dimension>
inline Vector<dimension>& Particle<dimension>::get_velocity()
{
	return velocity;
}

template<unsigned int dimension>
inline Vector<dimension> Particle<dimension>::get_velocity() const
{
	return velocity;
}

//template<unsigned int dimension>
//inline Particle<dimension> Particle<dimension>::accelerate(Vector<dimension>&& delta_v)
//{
//	this->velocity += std::move(delta_v);
//	return *this;
//}

template<unsigned int dimension>
Particle<dimension> & Particle<dimension>::set_mass(double m)
{
	if (m < 0)
	{
		std::cerr << "Negative mass!" << std::endl;
		return *this;
	}
	this->mass = m;
	return *this;
}

template<unsigned int dimension>
inline Particle<dimension> & Particle<dimension>::set_kinetic_energy(double e)
{
	set_velocity(RandomVectorOnBall<dimension>(sqrt(2 * e / mass)));
	return *this;
}

template<unsigned int dimension>
double Particle<dimension>::kinetic_energy()
{
	return 1.0 / 2.0*velocity.length_square()*mass;
}
