#include "Effect.h"


Effect::Effect(void)
{
}


Effect::~Effect(void)
{
}

int Effect::Tick()
{
	mTimeLeft--;
	return mTimeLeft;
}