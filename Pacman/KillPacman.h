#pragma once
#include <vector>
#include "Effect.h"
#include "Entity.h"
#include <typeinfo>
//#include "Pacman.h"
//#include "Ghost.h"
class KillPacman : Effect
{
private:
	vector<Entity> mEnties;
public:
	int Run();
	void AddEntity(Entity);

	KillPacman();
	~KillPacman();
};

