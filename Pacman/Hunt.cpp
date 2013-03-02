#include "Hunt.h"

Hunt::Hunt(vec3* pacmanPos, Effect *effect)
{
	mPacmanPos = pacmanPos;
	SetEffect(effect);
	mLastDir = vec3 (0,0,-1);
	enterCross = true;
}


Hunt::Hunt()
{
	
}


Hunt::~Hunt()
{
}

vec3 Hunt::Update(int sur[4], vec3 *worldPos, float speed, vec3 *target)
{
	
	if (*worldPos == *target)
	{ 
		if ((mLastDir.x == 1 && sur[0] == 1 && sur[2] == 1 && sur[1] != 1)
			|| (mLastDir.x == -1 && sur[0] == 1 && sur[2] == 1 && sur[3] != 1)
			|| (mLastDir.z == 1 && sur[1] == 1 && sur[3] == 1 && sur[2] != 1)
			|| (mLastDir.z == -1 && sur[1] == 1 && sur[3] == 1 && sur[0] != 1))
		{
			*target += mLastDir;
			return mLastDir;
		}
		else
		{
		int i;
			while (true)
			{
				i = rand()%4;
				if ( i == 0 && sur[0] != 1)
				{
					mLastDir = vec3(0,0,-1);
					break;
				}
				else if ( i == 1 && sur[1] != 1)
				{
					mLastDir = vec3(1,0,0);
					break;
				}
				else if ( i == 2 && sur[2] != 1)
				{
					mLastDir = vec3(0,0,1);
					break;
				}
				else if ( i == 3 && sur[3] != 1)
				{
					mLastDir = vec3(-1,0,0);
					break;
				}
			}
		}
		*target += mLastDir;
		return mLastDir;
	}
	else
	{
		
		float dist = glm::length(*worldPos - *target);
		if (dist < speed)
		{
			*worldPos = *target;
			return vec3(0);
		}
		//mLastDir = glm::normalize(*worldPos - *target);
		return mLastDir;
		
	}

	
	/*
	if ((sur[0] != 1 || sur[2] != 1)&&(sur[1] != 1 || sur[3] != 1))
	{
		if (enterCross)
		{
			float dist = (*worldPos - *target).length();
			enterCross = false;
			if(dist <= speed)
			{
				*worldPos = *target;
			}
			int nextMove;
			while (true){
				nextMove = rand()%4;
				if(sur[1] != 1 && nextMove == 0){
					mLastDir = vec3(1,0,0);
					break;
				}else if (sur[0] != 1 && nextMove == 1){
					mLastDir = vec3(0,0,-1);
					break;
				}else if(sur[3] != 1 && nextMove == 2){
					mLastDir = vec3(-1,0,0);
					break;
				}else if (sur[2] != 1 && nextMove == 3){
					mLastDir = vec3(0,0,1);
					break;
				}
			}
		}
	} 
	else
		enterCross = true;
	return mLastDir;
	/*
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
	}
	else
		SetWorldPos(vec3(GetWorldPos() + mDirection * (GetSpeed())));
	
	0 = up
	1 = left
	2 = down
	3 = right
	vi kör en rand() AI först
	*/
	//Pathfinder mm.
}
