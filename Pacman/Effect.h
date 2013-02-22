#pragma once

class Effect
{
private:
	int mTimeLeft;
protected:
	int Tick();
public:
	virtual int Run() = 0; // abstract!

	int GetTimeLeft() 
		{ return mTimeLeft; }


	Effect();
	~Effect();
};

