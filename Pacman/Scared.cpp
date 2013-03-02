#include "Scared.h"


Scared::Scared(void)
{
}

Scared::Scared(vec3* pacmanPos, Effect *effect)
{
	mPacmanPos = pacmanPos;
	SetEffect(effect);
}


Scared::~Scared(void)
{
}

vec3 Scared::Update(int sur[4], float dist, vec3 &worldPos, float speed, vec3 &target)
{
	return vec3(0);
	// logik!!! Behöver surroundinggrid!
}