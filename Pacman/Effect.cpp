#include "Effect.h"


Effect::Effect(void)
{
	mTimeLeft = 1;
}

Effect::Effect(int timeLeft)
{
	mTimeLeft = timeLeft;
}

Effect::~Effect(void)
{
}

int Effect::Tick()
{
	mTimeLeft--;
	return mTimeLeft;
}