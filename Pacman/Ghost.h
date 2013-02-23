#ifndef GHOST_H_
#define GHOST_H_

#include "CommonIncludes.h"
#include "Entity.h"
#include "Effect.h"

class Ghost : public Entity
{
public:
	Ghost();

	int Update();
	Effect GetEffect()
		{ return mEffect; }
private:
	Effect mEffect;

};


#endif