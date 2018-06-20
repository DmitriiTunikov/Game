#pragma once

#include "math2d.h"

#include "IntersectData.h"

class Collider
{
public:
	enum
	{
		TYPE_SPHERE,
	};
private:
	int type;
public:
	Collider(int type) : type(type) {}

	IntersectData Intersect(Collider &other);

	virtual void Transform(const Vector2 &translation) {}
	
	virtual Vector2 GetCenter() { return Vector2(0, 0); }
	
	int GetType() { return type; }
};