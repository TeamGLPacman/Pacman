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
	delete mPacmanPos;
}

vec3 Scared::Update(int sur[4], vec3 *worldPos, float speed, vec3 *target)
{	
		
	return vec3(0);
	
}