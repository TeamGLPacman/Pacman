#include "Effect.h"


Effect::Effect(void)
{
	mTimeLeft = 1;
	mMaxTime = mTimeLeft;
}

Effect::Effect(int timeLeft)
{
	mTimeLeft = timeLeft;
	mMaxTime = mTimeLeft;
}

Effect::~Effect(void)
{
}

int Effect::Tick()
{
	mTimeLeft--;
	return mTimeLeft;
}
