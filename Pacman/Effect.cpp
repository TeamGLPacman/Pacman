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
void Effect::Reset()
{
	mTimeLeft = mMaxTime;
}
Effect::~Effect(void)
{
	
}

int Effect::Tick()
{
	mTimeLeft--;
	return mTimeLeft;
}

int Effect::GetMaxTime()
{
	return mMaxTime;
}