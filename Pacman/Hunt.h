#pragma once
#include "CommonIncludes.h"
class Hunt
{
private:
	vec3 *mPacmanPos;
public:
	Hunt(&vec3);
	Hunt(void);

	void Update();

	~Hunt(void);
};

