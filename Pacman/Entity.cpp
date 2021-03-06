#include "Entity.h"


Entity::Entity(void)
{
}
Entity::Entity( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size ) : 
	Object3D( modelID, textureID, shaderID, colour, worldPos, size ), mSpeed(speed), mModSpeed(0), mDirection(direction)
{
}

Entity::~Entity(void)
{
}

int Entity::Update(int* surrondings)
{
	return 0;
}

vec2 Entity::GetGridPosition()
{
	return vec2(mTargetPoint.x, mTargetPoint.z);
}

void Entity::ReSpawn()
{
	SetWorldPos(mSpawnPosition);
	mDirection = vec3(1,0,0);
	mTargetPoint = GetWorldPos();
	mNextDirection = mDirection;
}
void Entity::UpdateTargetPoint(bool canMove[4])
{

}
bool Entity::Collision(Object3D* obj, float collDist)
{
	float dist(glm::length(GetWorldPos() - obj->GetWorldPos()));

	if(dist <= collDist)
		return true;
	else
		return false;
}