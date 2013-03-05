#include "KillGhost.h"

KillGhost::KillGhost(Ghost *ghost) : Effect(1)
{
	mGhost = ghost;
}
int KillGhost::Run()
{
	int timeLeft = Tick();
	mGhost->ReSpawn(); // �ndra h�r! om vi ska ha att sp�ket g�r tillbaka!
	mGhost->SetDefaultBehaviour();
	return 5; // 5 points
}
void KillGhost::AddPacman(Pacman *pacman)
{
	cout << "a" << endl;
}
void KillGhost::AddEntity(Entity *entity)
{
	mGhost = (Ghost*)entity;
}
