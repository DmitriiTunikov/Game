#pragma once

#include <vector>

#include "PhysicsEngine.h"
#include "BoundingCircle.h"

#include "object.h"

class Bullet{

public:
	Bullet(PhysicsEngine &phEngine, Vector2 &position, Vector2 &velocity, float radius)
	{
		Collider *colliderBullet = new BoundingCircle(position, radius);
		PhysicsObject phBullet(colliderBullet, velocity);
		phEngine.AddObject(phBullet);
	}
private:

};