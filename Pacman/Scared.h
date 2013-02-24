#ifndef SCARED_H_
#define SCARED_H_

#include "CommonIncludes.h"
#include "Effect.h"
#include "Entity.h"

class Scared : public Effect
{
private:
	vec3 *mPacmanPos;
public:
	Scared(vec3*);
	Scared(void);

	int Run();
	void AddEntity(Entity);

	~Scared(void);
};

#endif
