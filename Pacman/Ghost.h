#ifndef GHOST_H_
#define GHOST_H_

#include "CommonIncludes.h"
#include "Entity.h"
#include "Effect.h"
#include "Behaviour.h"

class Ghost : public Entity
{
public:
	Ghost();

	int Update();

	void SetDefaultBehaviour()
		{ mBehaviour = mDefualtBehaviour; }
	void SetBehaviour(Behaviour *set)
		{ mBehaviour = set; }
	Effect* GetEffect()
		{ return mBehaviour->GetEffect(); }

private:

	Behaviour *mBehaviour;
	Behaviour *mDefualtBehaviour;
};


#endif