#include "vector2.h"

class Gun{
	enum ammo_t{
		BULLETS
	};
private:
	Vector2 orientation;
	ammo_t type;
public:
	void Fire();
	void SetOrientation(Vector2 &orient);
};