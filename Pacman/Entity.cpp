#include "Entity.h"


Entity::Entity(void)
{
}
Entity::Entity( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size ) : 
	Object3D( modelID, textureID, shaderID, worldPos, size )
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
	SetWorldPos(mSpawnPosition);
}
void Entity::UpdateTargetPoint(bool canMove[4])
{

}
bool Entity::Collision(Object3D* obj, float dist)
{
	return false;
}