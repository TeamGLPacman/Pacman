#ifndef EFFECT_H_
#define EFFECT_H_

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

	Effect(int);
	Effect();
	~Effect();
};

#endif
