#ifndef HUNT_H_
#define HUNT_H_

#include "CommonIncludes.h"
#include "Behaviour.h"

class Hunt : public Behaviour
{
private:
	vec3 *mPacmanPos;
	vec3 mLastDir;
	bool enterCross;
public:

	Hunt(vec3* pacmanPos, Effect* effect);
	Hunt();

	vec3 Update(int sur[4], vec3 *worldPos, float speed, vec3 *target);

	~Hunt();
};

#endif