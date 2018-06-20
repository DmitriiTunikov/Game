#include "BoundingCircle.h"


IntersectData BoundingCircle::IntersectBoundingCircle(BoundingCircle& other)
{
	float radiusDistance = radius + other.GetRadius();
	Vector2 direction = (other.GetCenter() - center);
	float centerDistance = direction.magnitude();
	direction *= 1 / centerDistance;
	float distance = centerDistance - radiusDistance;

	return IntersectData(distance < 0, direction * distance);
}

void BoundingCircle::Transform(const Vector2 &translation)
{
	center += translation;
}