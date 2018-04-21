#pragma once

#include "math2d.h"

class IntersectData
{
private:
	bool  doesIntersect;
	Vector2 direction;
public:
	IntersectData(bool doesIntersect, Vector2 direction) : doesIntersect(doesIntersect), direction(direction) {}

	bool GetDoesIntersect() { return doesIntersect; }
	float GetDistance() { return direction.magnitude(); }
	Vector2 GetDirection() { return direction; }
};

