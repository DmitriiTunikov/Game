#pragma once

#include "collider.h"
#include "IntersectData.h"

#include "math2d.h"

class BoundingCircle : public Collider
{
private:
	Vector2 center;
	float radius;
public:
	BoundingCircle(Vector2 &center, float radius) : Collider(Collider::TYPE_SPHERE), center(center), radius(radius) {}
	BoundingCircle(float cX, float cY, float radius) : Collider(Collider::TYPE_SPHERE), center(cX, cY), radius(radius) {}

	IntersectData IntersectBoundingCircle(BoundingCircle &other);

	virtual void Transform(const Vector2 &translation);


	virtual Vector2 GetCenter() { return center; }
	float GetRadius() { return radius; }
};

