#pragma once

class Vector2{
public:
	float x;
	float y;
public:
	Vector2() : x(0), y(0) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	void vecSet(const Vector2& v) { x = v.x; y = v.y; }

	void Invert(void);

	void operator+=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;

	void operator-=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;

	void operator*=(const float value);
	Vector2 operator*(const float value) const;


	Vector2 componentProduct(const Vector2 &vector) const;
	void componentProductUpdate(const Vector2 &vector);

	float scalarProduct(const Vector2 &vector) const;
	float operator *(const Vector2 &vector) const;
	void Vector2::addScaledVector(const Vector2& vector, float scale);

	float magnitude() const;
	float squareMagnitude() const;

	void normalise();
	Vector2 unit() const;

	Vector2 vecRotate(float angle) const;
	void rotate(float angle);
	float angleBetween(const Vector2 &v);


	Vector2 Reflect(Vector2 Normal) const;

	void clear();
};
