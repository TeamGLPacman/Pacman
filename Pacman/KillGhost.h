#ifndef KILLGHOST_H_
#define KILLGHOST_H_

#include "Effect.h"
#include "Ghost.h"
#include "Entity.h"

class KillGhost : public Effect
{
private:
	Ghost *mGhost;
public:

	int Run();
	void AddPacman(Pacman* pacman);
	void AddEntity(Entity *entity);
	bool isGhostDead() { return true; }
	KillGhost(Ghost *ghost);
	//~KillGhost();
};

#endif