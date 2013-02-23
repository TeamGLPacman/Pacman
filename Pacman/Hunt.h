#ifndef HUNT_H_
#define HUNT_H_

#include "CommonIncludes.h"
#include "Behaviour.h"

class Hunt : public Behaviour
{
private:
	vec3 *mPacmanPos;
public:

	Hunt(vec3*);
	Hunt();

	void Update();

	~Hunt();
};

#endif