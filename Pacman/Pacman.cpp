#include "Pacman.h"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

Pacman::Pacman( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size ) : 
	Entity( speed, direction, modelID, textureID, shaderID, colour, worldPos, size ), mLives(3), mInputTimer(0)
{
	SetWorldPos(worldPos);
	SetSpawnPosition(worldPos);
	mNextDirection = direction;
	mTargetPoint = worldPos + direction;
}


int Pacman::TakeDamaga()
{
	mLives--;
	cout << mLives << endl;
	return mLives;
}
//Converts a vector to one of four int values (1=up, 2=right, 3=down, 4= left)
int Pacman::GetVecInt(vec3 theVec3)
{
	vec3 vec(glm::normalize(theVec3));
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
	float dist(glm::length(GetWorldPos() - mTargetPoint));

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
		SetWorldPos(vec3(GetWorldPos() + mDirection * (GetSpeed())));

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
	if(mInputTimer > 1)
	{
		if(GetAsyncKeyState('L') != 0 || GetAsyncKeyState(VK_RIGHT) != 0)
		{
			mNextDirection =  glm::cross(mDirection, vec3(0,1,0));
			mInputTimer = 0;
		}
		else if(GetAsyncKeyState('J') != 0 || GetAsyncKeyState(VK_LEFT) != 0)
		{
			mNextDirection = -glm::cross(mDirection, vec3(0,1,0));
			mInputTimer = 0;
		}
		else if(GetAsyncKeyState('K') != 0 || GetAsyncKeyState(VK_DOWN) != 0)
		{
			mNextDirection =  -mDirection;
			mInputTimer = 0;
		}
		else if(GetAsyncKeyState('I') != 0 || GetAsyncKeyState(VK_DOWN) != 0)
		{
			mNextDirection =  mDirection;
			mInputTimer = 0;
		}
	}
	mInputTimer+= 0.1;
}
