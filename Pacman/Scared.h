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
public:
	Scared(vec3*, Effect*);
	Scared(void);

	void Update();
	void AddEntity(Entity*);

	~Scared(void);
};

#endif
