#ifndef EFFECT_H_
#define EFFECT_H_
#include "Pacman.h"

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
	void Reset();
	virtual int Run() = 0; // abstract!
	virtual void AddEntity(Entity*) = 0;
	virtual void AddPacman(Pacman*) = 0;

	int GetTimeLeft() 
		{ return mTimeLeft; }
};

#endif
