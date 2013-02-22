#include "Points.h"

Points::Points()
{
}

Points::Points(int points)
{
	mPoints = points;
}

int Points::Run()
{
	Tick();
	return mPoints;
}