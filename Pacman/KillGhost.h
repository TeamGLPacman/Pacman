#ifndef KILLGHOST_H_
#define KILLGHOST_H_

#include "Effect.h"
#include "Ghost.h"
#include "Entity.h"

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

#endif