#include "Points.h"

Points::Points(int points) : mPoints(points)
{
	
}

Points::~Points()
{ }

int Points::Run()
{
	Tick();
	return mPoints;
}