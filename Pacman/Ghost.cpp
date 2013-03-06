#include "Ghost.h"

Ghost::Ghost( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size , Behaviour *behaviour) : 
	Entity( speed, direction, modelID, textureID, shaderID, colour, worldPos, size )
{
	SetSpawnPosition(worldPos);
	mBehaviour = behaviour;
	mDefualtBehaviour = behaviour;
	mTargetPoint = worldPos;
	mDirection = vec3(0,0,-1);
}
vec2 Ghost::GetGridPos(){
	vec3 pos = GetWorldPos();
	vec2 returnv;
	if (floor(pos.x) == floor(pos.x+0.2))
		returnv.x = floor(pos.x);
	else
	{
		returnv.x = floor(pos.x+1);
	}
	if (floor(pos.z) == floor(pos.z+0.2))
		returnv.y = floor(pos.z);
	else
	{
		returnv.y = floor(pos.z+1);
	}
	return returnv;
}
Ghost::~Ghost()
{
	delete mBehaviour;
	delete mDefualtBehaviour;
}
int Ghost::Update(int sur[4])
{
	vec3 a= mBehaviour->Update(sur, GetPositionPointer(), GetSpeed(), &mTargetPoint);
	SetDirection(a);
	SetWorldPos(vec3(GetWorldPos() + mDirection * (GetSpeed())));
	return 0;
}