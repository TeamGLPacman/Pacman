#ifndef SCARED_H_
#define SCARED_H_

#include "CommonIncludes.h"
class Scared
{
private:
	vec3 *mPacmanPos;
public:
	Scared(vec3*);
	Scared(void);

	void Update();

	~Scared(void);
};

#endif
