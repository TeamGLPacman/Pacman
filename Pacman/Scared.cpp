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
void Scared::AddEntity(Entity *entity)
{
}
void Scared::Update()
{
	// logik!!! Behöver surroundinggrid!
}