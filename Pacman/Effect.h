#ifndef EFFECT_H_
#define EFFECT_H_

class Effect
{
private:
	int mMaxTime;
	int mTimeLeft;
protected:
	int Tick();
	int GetMaxTime();
public:
	Effect(int);
	Effect();
	~Effect();

	virtual int Run() = 0; // abstract!

	int GetTimeLeft() 
		{ return mTimeLeft; }
};

#endif
