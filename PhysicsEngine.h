#pragma once

#include <vector>

#include "PhysicObject.h"

class PhysicsEngine
{
private:
	std::vector<PhysicsObject> objects;
public:
	PhysicsEngine() {}

	void AddObject(PhysicsObject &object);
	
	void Simulate(float delta);
	std::vector<unsigned int[2]> HandleCollisions();

	PhysicsObject &GetObject(unsigned int index);
	unsigned int GetNumObjects();
};