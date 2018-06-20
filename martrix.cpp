#include "matrix.h"

Matrix2::Matrix2()
{
	data[0] = data[3] = 1;
	data[1] = data[2] = 0;
}

Matrix2::Matrix2(float angle)
{
	data[0] = cos(angle);
	data[1] = -sin(angle);
	data[2] = sin(angle);
	data[3] = cos(angle);
}

Vector2 Matrix2::operator*(const Vector2 &vector) const
{
	return Vector2(
		vector.x * data[0] +
		vector.y * data[1],

		vector.x * data[2] +
		vector.y * data[3]
		);
}