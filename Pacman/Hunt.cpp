#include "Hunt.h"

Hunt::Hunt(vec3* pacmanPos)
{
	mPacmanPos = pacmanPos;
}

Hunt::Hunt()
{
	
}


Hunt::~Hunt()
{
}

void Hunt::Update()
{
	int turn = rand()%4;
	/*
	0 = up
	1 = left
	2 = down
	3 = right
	vi k�r en rand() AI f�rst
	*/
	//Pathfinder mm.
}
