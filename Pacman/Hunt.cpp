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
	vi kör en rand() AI först
	*/
	//Pathfinder mm.
}
