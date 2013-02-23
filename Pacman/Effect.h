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
	virtual int Run(); // abstract!

	int GetTimeLeft() 
		{ return mTimeLeft; }

	Effect(int);
	Effect();
	~Effect();
};

#endif
