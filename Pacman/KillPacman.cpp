#include "KillPacman.h"

KillPacman::KillPacman()
{
}
KillPacman::~KillPacman()
{
}
int KillPacman::Run()
{

	int timeLeft = Tick();

	if (timeLeft == GetMaxTime()-1)
	{
		mPacman->ReSpawn();
		mPacman->TakeDamaga();
		for (int i = 0; i < mEnties.size(); i++)
		{
			mEnties[i]->ReSpawn();
		}
	}
	return 0;
}

void KillPacman::AddEntity(Entity* entity)
{
	mEnties.push_back(entity);
}
void KillPacman::AddPacman(Pacman* pacman)
{
	mPacman = pacman;
}