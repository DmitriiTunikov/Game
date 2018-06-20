#pragma once

class Shape
{
private:
	float x, y;
public:
	virtual void Draw() = 0;

	void SetCoord(float _x, float _y) { x = _x; y = _y; }
};

class Circle : Shape
{
private:
	float radius;
public:
	void Draw();

	void SetRadius();
	float GetRadius();
};

class Rectangle : Shape
{
private:
	float a, b;
public:
	void Draw();

	void SetSides(float _a, float _b) { a = _a; b = _b }
};