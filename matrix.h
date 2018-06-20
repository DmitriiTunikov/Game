#pragma once

#include <math.h>

#include "vector2.h"

class Matrix2{
	float data[4];

public:
	Matrix2();
	Matrix2(float angle);

	Vector2 operator*(const Vector2 &vector) const;
};