#include "vector2.h"
#include "matrix.h"

void Vector2::Invert()
{
	x = -x;
	y = -y;
}

void Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;
}

Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

void Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}


void Vector2::operator*=(const float value)
{
	x *= value;
	y *= value;
}

Vector2 Vector2::operator*(const float value) const
{
	return Vector2(x*value, y*value);
}

Vector2 Vector2::componentProduct(const Vector2 &vector) const
{
	return Vector2(x * vector.x, y * vector.y);
}

void Vector2::componentProductUpdate(const Vector2 &vector)
{
	x *= vector.x;
	y *= vector.y;
}

float Vector2::scalarProduct(const Vector2 &vector) const
{
	return x*vector.x + y*vector.y;
}

float Vector2::angleBetween(const Vector2 &v2)
{
	return acos((*this) * v2 / magnitude() / v2.magnitude());
}

float Vector2::operator *(const Vector2 &vector) const
{
	return x*vector.x + y*vector.y;
}

void Vector2::addScaledVector(const Vector2& vector, float scale)
{
	x += vector.x * scale;
	y += vector.y * scale;
}

float Vector2::magnitude() const
{
	return sqrt(x*x + y*y);
}

float Vector2::squareMagnitude() const
{
	return x*x + y*y;
}

void Vector2::normalise()
{
	float l = magnitude();
	if (l > 0)
	{
		(*this) *= ((float)1) / l;
	}
}

Vector2 Vector2::unit() const
{
	Vector2 result = *this;
	result.normalise();
	return result;
}

void Vector2::clear()
{
	x = y = 0;
}


Vector2 Vector2::vecRotate(float angle) const
{
	return Matrix2(angle) * (*this);
}

void Vector2::rotate(float angle)
{
	Vector2 vec = Matrix2(angle) * (*this);

	vecSet(vec);
}

Vector2 Vector2::Reflect(Vector2 Normal) const
{
	return (*this) - Normal * 2 * ((*this) * Normal);
}