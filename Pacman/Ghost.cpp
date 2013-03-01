#include "Ghost.h"

Ghost::Ghost( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size , Behaviour *behaviour) : 
	Entity( speed, direction, modelID, textureID, shaderID, worldPos, size )
{
	SetSpawnPosition(worldPos);
	mBehaviour = behaviour;
	mDefualtBehaviour = behaviour;
}

int Ghost::Update()
{
	return 0;
}