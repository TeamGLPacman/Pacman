#include "Pacman.h"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

Pacman::Pacman( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size ) : 
	Entity( speed, direction, modelID, textureID, shaderID, worldPos, size )
{
	SetWorldPos(worldPos);
	SetSpawnPosition(worldPos);
	mNextDirection = direction;
	mTargetPoint = worldPos + direction;
	mInputTimer = 0;
	mPressIndicator = 0;
}

vec2 Pacman::GetGridPosition()
{
	return vec2(mTargetPoint.x, mTargetPoint.z);
}

//Converts a vector to one of four int values (1=up, 2=right, 3=down, 4= left)
int Pacman::GetVecInt(vec3 theVec3)
{
	vec3 vec = glm::normalize(theVec3);
	int i;

	if( vec == vec3(0,0,-1) )
		i = 0;
	else if( vec == vec3(1,0,0) )
		i = 1;
	else if( vec == vec3(0,0,1) )
		i = 2;
	else
		i = 3;

	return i;
}

int Pacman::Update(int surroundingGrid[4])
{
	float dist = glm::length(GetWorldPos() - mTargetPoint);

	if(dist <= GetSpeed())
	{
		SetWorldPos(mTargetPoint);

		if(surroundingGrid[GetVecInt(mNextDirection)] != 1)
		{
			mTargetPoint += mNextDirection;
			mDirection = mNextDirection;
		}
		else if(surroundingGrid[GetVecInt(mDirection)] != 1)
		{
			mTargetPoint += mDirection;
		}
		else
			mTargetPoint = mTargetPoint;
	}
	else
		SetWorldPos(vec3(GetWorldPos() + mDirection * GetSpeed()));

	if(mNextDirection == -mDirection)
	{
		if(surroundingGrid[GetVecInt(mNextDirection)] != 1)
		{
			mTargetPoint += mNextDirection;
			mDirection = mNextDirection;
		}
	}

	InputHandler();
	
	return 0;
}

void Pacman::InputHandler()
{
	if(GetAsyncKeyState('L') != 0)
	{
		mPressIndicator = 1;
	}
	else if(mPressIndicator == 1)
	{
		mNextDirection = glm::cross(mDirection, vec3(0,1,0));
		mPressIndicator = 0;
	}
	else if(GetAsyncKeyState('J') != 0)
	{
		mPressIndicator = 2;
	}
	else if(mPressIndicator == 2)
	{
		mNextDirection = -glm::cross(mDirection, vec3(0,1,0));
		mPressIndicator = 0;
	}
	else if(GetAsyncKeyState('K') != 0)
	{
		mPressIndicator = 3;
	}
	else if(mPressIndicator == 3)
	{
		mNextDirection *= -1;
		mPressIndicator = 0;
	}
}