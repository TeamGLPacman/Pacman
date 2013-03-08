#include "Effect.h"


Effect::Effect(void) : mTimeLeft(1), mMaxTime(1)
{
}

Effect::Effect(int timeLeft) : mTimeLeft(timeLeft), mMaxTime(timeLeft)
{
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