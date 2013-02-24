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

int Entity::Update(int* surrondings)
{
	return 0;
}
void Entity::ReSpawn()
{
	
}
void Entity::UpdateTargetPoint(bool canMove[4])
{

}
bool Entity::Collision(Object3D obj, float dist)
{
	return false;
}