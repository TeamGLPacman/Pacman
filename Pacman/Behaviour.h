#ifndef BEHAVIOUR_H_
#define BEHAVIOUR_H_

#include "Effect.h"
#include "Entity.h"
#include "CommonIncludes.h"

class Behaviour
{
private:
	Effect *mEffect;
protected:
	void SetEffect(Effect* effect)
		{ mEffect = effect; }
public:
	virtual vec3 Update(int sur[4], vec3 *worldPos, float speed, vec3 *target) = 0; // abstract

	Effect* GetEffect() 
		{ return mEffect; }

	Behaviour(){}
	~Behaviour() {
		delete mEffect;
	}
};

#endif