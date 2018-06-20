#pragma once

#include "collider.h"
#include "BoundingCircle.h"

#include "math2d.h"

class PhysicsObject
{
private:
	float inverseMass;

	float damping;

	Vector2 oldPosition;
	Vector2 position;
	Vector2 orientation;
	Vector2 velocity;
	Vector2 forceAccum;

	Vector2 acceleration;

	float rotation;

	Collider *collider;
public:
	PhysicsObject(Collider* collider, const Vector2 &velocity) : position(collider->GetCenter()),oldPosition(collider->GetCenter()), velocity(velocity), collider(collider) {}
	~PhysicsObject();
//	PhysicsObject operator=(PhysicsObject other);
	
	void Integrate(float delta);

	Vector2 &GetPosition() { return position; }
	Vector2 &GetVelocity() { return velocity; }

	Collider& GetCollider();
	float GetRadius() { return ((BoundingCircle *)collider)->GetRadius(); }

	void SetMass(float mass);
	float GetMass();

	void SetInverseMass(float inverseMass);
	float GetInverseMass();

	bool HasFiniteMass();

	void SetDamping(float damping);
	float GetDamping();

	void SetPosition(Vector2 &position);
	void SetPosition(float x, float y);

	void SetVelocity(Vector2 &velocity);
	void SetVelocity(float x, float y);

	void SetAcceleration(Vector2 &acceleration);
	void SetAcceleration(float x, const float y);

	void GetAcceleration(Vector2 *acceleration);
	Vector2 GetAcceleration();

	void ClearAccumulator();

	void AddForce(Vector2 &force);
};


