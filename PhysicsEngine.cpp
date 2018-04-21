#include "PhysicsEngine.h"

void PhysicsEngine::AddObject(PhysicsObject &object)
{
	objects.push_back(object);
}

void PhysicsEngine::Simulate(float delta)
{
	unsigned int i;
	for (i = 0; i < objects.size(); i++)
		objects[i].Integrate(delta);
}

PhysicsObject &PhysicsEngine::GetObject(unsigned int index)
{
	return objects[index];
}

unsigned int PhysicsEngine::GetNumObjects()
{
	return (unsigned int)objects.size();
}

std::vector<unsigned int[2]> PhysicsEngine::HandleCollisions()
{
	unsigned int i, j;
	std::vector<unsigned int[2]> collisedPairs;
	
	for (i = 0; i < objects.size(); i++)
	{
		for (j = i + 1; j < objects.size(); j++)
		{
			IntersectData intersectData = objects[i].GetCollider().Intersect(objects[j].GetCollider());

			if (intersectData.GetDoesIntersect())
			{

				Vector2 direction = intersectData.GetDirection();
				direction.normalise();
				//Vector2 otherDirection = Vector2(direction.Reflect(objects[i].GetVelocity()));
				//otherDirection.normalise();
				Vector2 otherDirection = direction * (-1);

				objects[i].SetVelocity(Vector2(objects[i].GetVelocity().Reflect(otherDirection)));
				objects[j].SetVelocity(Vector2(objects[j].GetVelocity().Reflect(direction)));

				/*Vector2 direction = intersectData.GetDirection();
				direction.normalise();
				Vector2 otherDirection = Vector2(direction.Reflect(objects[i].GetVelocity().Normalized()));

				objects[i].SetVelocity(Vector2(m_objects[i].GetVelocity().Reflect(otherDirection)));
				objects[j].SetVelocity(Vector2(m_objects[j].GetVelocity().Reflect(direction)));
				*/
			}
		}
	}
	return collisedPairs;
}