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
	vec3 mLastDir;

	void SetEffect(Effect* effect)
		{ mEffect = effect; }
public:
	virtual vec3 Update(int sur[4], vec3 *worldPos, float speed, vec3 *target) = 0; // abstract

	Effect* GetEffect() 
		{ return mEffect; }

	vec3 GetLastDir()
	{ return mLastDir; }

	void SetLastDir(vec3 lastDir)
	{ mLastDir = lastDir; }

	Behaviour(){}
	~Behaviour() {
		delete mEffect;
	}
};

#endif