#pragma once

#include "object.h"
#include "gun.h"
#include "PhysicsEngine.h"
#include "BoundingCircle.h"

#include "math2d.h"

#include <math.h>

class car : public Object
{
private:
	Gun Weapon;
private:

public:
	car(PhysicsEngine &phEngine)
	{
		Collider *colliderBullet = new BoundingCircle(position, radius);
		PhysicsObject phCar(colliderCar, Vector2());
		phEngine.AddObject(phCar);
	}

    ~car();
   
    void Draw();

    void Brake();
    void Accelerate();
	void TurnRight();
	void TurnLeft();
	void SetGunOrientation();

    void Fire();

	/*void Update(float duration)
	{
		velocity += (acselerate * duration);
		position += (velocity * duration);

		if (velocity.magnitude() > 1)
			orientation = velocity * (1.0 / velocity.magnitude());

		MakeMove();
	}
	void MakeMove()
	{
		Vector2 tractionForce = orientation * engineForce;
		Vector2 breakingForce = orientation * (-brakingC);
		Vector2 airdragForce = orientation * (-airdragC) * velocity.magnitude();
		Vector2 WheelDragForce = velocity * (-dragC);
		Vector2 longForce;
		Vector2 vLateral;
		Vector2 vLong;
		float w, b, c;
		float steeringAngle;
		bool vLongSgn = vLong.magnitude() > 0 ? 1 : -1;
		double slipAngleFront = (atan(vLateral.magnitude() + w * b) / vLong.magnitude()) - steeringAngle * vLongSgn;
		double slipAngleRear = (atan(vLateral.magnitude() - w * c) / vLong.magnitude());
		Vector2 fLat;


		Vector2 fLatFront;
		Vector2 fLatRear;

		double Torque = cos(steeringAngle) * fLatFront.magnitude() * b - fLatRear.magnitude() * c;

	}*/
 };
