#ifndef POWERPACMAN_H_
#define POWERPACMAN_H_

#include "Effect.h"
#include "Scared.h"
#include "Entity.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Behaviour.h"
#include "Scared.h"

class PowerPacman : public Effect
{
private:
	vector<Ghost*> mAffectedGhosts;
	Pacman *mPacman;
public:

	int Run();
	void AddEntity(Entity*);
	void AddPacman(Pacman*);

	PowerPacman(void);
	~PowerPacman(void);
};

#endif