#pragma once

#include "vector2.h"

#define float_MAX (1000000000000)

class Particle
{
public:
	float inverseMass;

	float damping;

	Vector2 position;
	Vector2 velocity;
	Vector2 forceAccum;

	Vector2 acceleration;

public:
	void integrate(float duration);

	void setMass(const float mass);
	float getMass() const;

	void setInverseMass(const float inverseMass);
	float getInverseMass() const;

	bool hasFiniteMass() const;


	void setDamping(const float damping);
	float getDamping() const;


	void setPosition(const Vector2 &position);
	void setPosition(const float x, const float y);

	void getPosition(Vector2 *position) const;
	Vector2 getPosition() const;


	void setVelocity(const Vector2 &velocity);
	void setVelocity(const float x, const float y);

	void getVelocity(Vector2 *velocity) const;
	Vector2 getVelocity() const;


	void setAcceleration(const Vector2 &acceleration);
	void setAcceleration(const float x, const float y);


	void getAcceleration(Vector2 *acceleration) const;
	Vector2 getAcceleration() const;


	void clearAccumulator();

	void addForce(const Vector2 &force);
};
