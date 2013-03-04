#ifndef SCARED_H_
#define SCARED_H_

#include "CommonIncludes.h"
#include "Behaviour.h"
#include "Effect.h"
#include "Entity.h"

class Scared : public Behaviour
{
private:
	vec3 *mPacmanPos;
	vec3 mLastDir;
	bool enterCross;
public:
	Scared(vec3* pacmanPos, Effect* effect);
	Scared(void);

	vec3 Update(int sur[4], vec3 *worldPos, float speed, vec3 *target);

	~Scared(void);
};

#endif
