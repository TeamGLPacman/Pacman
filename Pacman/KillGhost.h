#pragma once
#include "Effect.h"
//#include "Ghost.h"
class KillGhost : public Effect
{
private:
	Ghost mGhost;
public:
	int Run();
	void AddEntity(Entity);

	KillGhost();
	~KillGhost();
};

