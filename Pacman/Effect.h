#pragma once

class Effect
{
private:
	int mMaxTime;
	int mTimeLeft;
protected:
	int Tick();
	int GetMaxTime();
public:
	virtual int Run() = 0; // abstract!

	int GetTimeLeft() 
		{ return mTimeLeft; }

	Effect(int);
	Effect();
	~Effect();
};

