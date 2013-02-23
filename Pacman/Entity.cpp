#include "Entity.h"


Entity::Entity(void)
{
}
Entity::Entity(float speed, vec3 direction)
{
	mSpeed = speed;
	mDirection = direction;
}

Entity::~Entity(void)
{
}

int Update()
{
	return 0;
}
void ReSpawn()
{
	
}
void UpdateTargetPoint(bool canMove[4])
{

}
bool Collision(Object3D obj, float dist)
{
	return false;
}