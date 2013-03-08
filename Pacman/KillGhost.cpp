#include "KillGhost.h"

KillGhost::KillGhost(Ghost *ghost) : Effect(1), mGhost(ghost)
{
}
KillGhost::~KillGhost()
{
	delete mGhost;
}
int KillGhost::Run()
{
	int timeLeft(Tick());
	mGhost->ReSpawn(); // ändra här! om vi ska ha att spöket går tillbaka!
	mGhost->SetDefaultBehaviour();
	return 5; // 5 points
}
void KillGhost::AddPacman(Pacman *pacman)
{


}
void KillGhost::AddEntity(Entity *entity)
{
	mGhost = (Ghost*)entity;
}
