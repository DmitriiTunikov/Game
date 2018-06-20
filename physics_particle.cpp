#include "physics_particle.h"
#include "vector2.h"

#include <assert.h>
#include <math.h>

void Particle::integrate(float duration)
{
	if (inverseMass <= 0.0f) 
		return;

	position.addScaledVector(velocity, duration);

	Vector2 resultingAcc = acceleration;
	resultingAcc.addScaledVector(forceAccum, inverseMass);

	velocity.addScaledVector(resultingAcc, duration);
	velocity *= pow(damping, duration);
	
	clearAccumulator();
}


void Particle::setMass(const float mass)
{
	Particle::inverseMass = ((float)1.0) / mass;
}

float Particle::getMass() const
{
	if (inverseMass == 0)
		return (float)float_MAX;
	else
		return ((float)1.0) / inverseMass;
}

void Particle::setInverseMass(const float inverseMass)
{
	Particle::inverseMass = inverseMass;
}

float Particle::getInverseMass() const
{
	return inverseMass;
}

bool Particle::hasFiniteMass() const
{
	return inverseMass >= 0.0f;
}

void Particle::setDamping(const float damping)
{
	Particle::damping = damping;
}

float Particle::getDamping() const
{
	return damping;
}

void Particle::setPosition(const Vector2 &position)
{
	Particle::position = position;
}

void Particle::setPosition(const float x, const float y)
{
	position.x = x;
	position.y = y;
}

void Particle::getPosition(Vector2 *position) const
{
	*position = Particle::position;
}

Vector2 Particle::getPosition() const
{
	return position;
}

void Particle::setVelocity(const Vector2 &velocity)
{
	Particle::velocity = velocity;
}

void Particle::setVelocity(const float x, const float y)
{
	velocity.x = x;
	velocity.y = y;
}

void Particle::getVelocity(Vector2 *velocity) const
{
	*velocity = Particle::velocity;
}

Vector2 Particle::getVelocity() const
{
	return velocity;
}

void Particle::setAcceleration(const Vector2 &acceleration)
{
	Particle::acceleration = acceleration;
}

void Particle::setAcceleration(const float x, const float y)
{
	acceleration.x = x;
	acceleration.y = y;
}

void Particle::getAcceleration(Vector2 *acceleration) const
{
	*acceleration = Particle::acceleration;
}

Vector2 Particle::getAcceleration() const
{
	return acceleration;
}

void Particle::clearAccumulator()
{
	forceAccum.clear();
}

void Particle::addForce(const Vector2 &force)
{
	forceAccum += force;
}