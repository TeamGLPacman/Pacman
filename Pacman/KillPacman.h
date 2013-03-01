#ifndef KILLPACMAN_H_
#define KILLPACMAN_H_

//#include "CommonIncludes.h"
#include "Effect.h"
#include "Entity.h"
#include "Pacman.h"
#include "Ghost.h"

class KillPacman : public Effect
{
private:
	Pacman *mPacman;
	vector<Entity*> mEnties;
public:
	int Run();
	void AddEntity(Entity *newEntity);
	void AddPacman(Pacman *pacman);

	KillPacman();
	~KillPacman();
};

#endif