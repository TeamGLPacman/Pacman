#include "Hunt.h"

Hunt::Hunt(vec3* pacmanPos, Effect *effect)
{
	mPacmanPos = pacmanPos;
	SetEffect(effect);
	SetLastDir(vec3 (0,0,-1));
	enterCross = true;
}


Hunt::Hunt()
{
	
}


Hunt::~Hunt()
{
	delete mPacmanPos;
}

vec3 Hunt::Update(int sur[4], vec3 *worldPos, float speed, vec3 *target)
{
	
	vec3 distancefrompacman = *mPacmanPos - *worldPos;
	vector <int> vLeft, vRight, vUp, vDown;
	float lengthx = distancefrompacman.x; //  x
	float lengthz = distancefrompacman.z; // "y"
	int i = 0;
	if(lengthx < 0)
	{
		while(i < 6)
		{
			vLeft.push_back(i);
			i++;
		}
		vRight.push_back(i);
		i++;
	}
	else if (lengthx > 0)
	{
		while(i < 6)
		{
			vRight.push_back(i);
			i++;
		}
		vLeft.push_back(i);
		i++;
	}
	else
	{
		while(i < 7)
		{
			vRight.push_back(i);
			i++;
			vLeft.push_back(i);
			i++;
		}
		
	}
	if(lengthz < 0)
	{
		while(i < 13)
		{ 
			vUp.push_back(i);
			i++;
		}
		vDown.push_back(i);
		i++;
	}
	else if (lengthx > 0)
	{
		while(i < 13)
		{
			vDown.push_back(i);
			i++;
		}
		vUp.push_back(i);
		i++;
	}
	else
	{
		while(i < 14)
		{
			vDown.push_back(i);
			i++;
			vUp.push_back(i);
			i++;
		}
	}
	
	
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
				i = rand()%14;
				if (sur[0] != 1)
				{
					for (int j = 0; j < vUp.size(); j++)
					{
						if(i == vUp[j])
						{
							mLastDir = vec3(0,0,-1);
							*target += mLastDir;
							return mLastDir;
						}
					}
				}
				if (sur[2] != 1)
				{
					for (int j = 0; j < vDown.size(); j++)
					{
						if(i == vDown[j])
						{
							mLastDir = vec3(0,0,1);
							*target += mLastDir;
							return mLastDir;
						}
					}
				}
				if (sur[3] != 1)
				{
					for (int j = 0; j < vLeft.size(); j++)
					{
						if(i == vLeft[j])
						{
							mLastDir = vec3(-1,0,0);
							*target += mLastDir;
							return mLastDir;
						}
					}
				}
				if (sur[1] != 1)
				{
					for (int j = 0; j < vRight.size(); j++)
					{
						if(i == vRight[j])
						{
							mLastDir = vec3(1,0,0);
							*target += mLastDir;
							return mLastDir;
						}
					}
				}
			}
		}

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
}
