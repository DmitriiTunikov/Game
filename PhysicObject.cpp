#include <iostream>

#include "PhysicObject.h"
/*
PhysicsObject PhysicsObject::operator=(PhysicsObject other)
{
	char* temp[sizeof(PhysicsObject) / sizeof(char)];
	memcpy(temp, this, sizeof(PhysicsObject));
	memcpy(this, &other, sizeof(PhysicsObject));
	memcpy(&other, temp, sizeof(PhysicsObject));
}*/

PhysicsObject::~PhysicsObject()
{
	//if (collider) delete collider;
}

Collider& PhysicsObject::GetCollider()
{
	Vector2 translation = position - oldPosition;
	oldPosition = position;
	collider->Transform(translation);

	return *collider;
}


void PhysicsObject::Integrate(float duration)
{
//	if (inverseMass <= 0.0f) 
	//	return;

	position.addScaledVector(velocity, duration);

	//Vector2 resultingAcc = acceleration;
//	resultingAcc.addScaledVector(forceAccum, inverseMass);
	
	//velocity.addScaledVector(resultingAcc, duration);

	//velocity *= pow(damping, duration);

	//ClearAccumulator();
}



void PhysicsObject::SetMass(float mass)
{
	PhysicsObject::inverseMass = ((float)1.0) / mass;
}

float PhysicsObject::GetMass()
{
	if (inverseMass == 0) 
		return (float)1000000000;//float_MAX;
	else
		return ((float)1.0) / inverseMass;
}

void PhysicsObject::SetInverseMass(float inverseMass)
{
	PhysicsObject::inverseMass = inverseMass;
}

float PhysicsObject::GetInverseMass()
{
	return inverseMass;
}

bool PhysicsObject::HasFiniteMass()
{
	return inverseMass >= 0.0f;
}

void PhysicsObject::SetDamping(float damping)
{
	PhysicsObject::damping = damping;
}

float PhysicsObject::GetDamping()
{
	return damping;
}

void PhysicsObject::SetPosition(Vector2 &position)
{
	PhysicsObject::position = position;
}

void PhysicsObject::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void PhysicsObject::SetVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}


void PhysicsObject::SetVelocity(Vector2 &velocity)
{
	PhysicsObject::velocity = velocity;
}


void PhysicsObject::SetAcceleration(Vector2 &acceleration)
{
	PhysicsObject::acceleration = acceleration;
}

void PhysicsObject::SetAcceleration(float x, float y)
{
	acceleration.x = x;
	acceleration.y = y;
}

void PhysicsObject::GetAcceleration(Vector2 *acceleration)
{
	*acceleration = PhysicsObject::acceleration;
}

Vector2 PhysicsObject::GetAcceleration()
{
	return acceleration;
}

void PhysicsObject::ClearAccumulator()
{
	forceAccum.clear();
}

void PhysicsObject::AddForce(Vector2 &force)
{
	forceAccum += force;
}