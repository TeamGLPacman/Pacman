#include "Scared.h"


Scared::Scared(void)
{

}

Scared::Scared(vec3* pacmanPos, Effect *effect)
{
	mPacmanPos = pacmanPos;
	SetEffect(effect);
	mLastDir = vec3 (0,0,-1);
	enterCross = true;
}


Scared::~Scared(void)
{
}

vec3 Scared::Update(int sur[4], vec3 *worldPos, float speed, vec3 *target)
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
	//return vec3(0);
	// logik!!! Behöver surroundinggrid!
}