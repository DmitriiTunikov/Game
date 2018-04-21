#include "BoundingCircle.h"
#include "collider.h"

IntersectData Collider::Intersect(Collider &other)
{
	if (type == TYPE_SPHERE && other.GetType() == TYPE_SPHERE)
	{
		BoundingCircle *self = (BoundingCircle*)this;
		return self->IntersectBoundingCircle((BoundingCircle&)other);
	}

	return IntersectData(false, Vector2());
}