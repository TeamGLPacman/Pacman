#pragma once
#include "CommonIncludes.h"
class Scared
{
private:
	vec3 *mPacmanPos;
public:
	Scared(&vec3);
	Scared(void);

	void Updatge();

	~Scared(void);
};

