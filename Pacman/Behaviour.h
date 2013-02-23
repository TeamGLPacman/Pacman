#ifndef BEHAVIOUR_H_
#define BEHAVIOUR_H_

#include "Effect.h"
#include "Entity.h"

class Behaviour
{
private:
	Effect* mEffect;
public:
	virtual void Update() = 0; // abstract
	virtual void AddEntity(Entity) = 0; // abstract

	Effect* GetEffect() 
		{ return mEffect; }

	Behaviour();
	~Behaviour();
};

#endif