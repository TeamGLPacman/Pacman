#include "KillGhost.h"


KillGhost::KillGhost(void)
{
}

KillGhost::~KillGhost(void)
{
}

int KillGhost::Run()
{
	int timeLeft = Tick();
	if (timeLeft != 0)
	{
		//Ghost.ReSpawn(); // �ndra h�r! om vi ska ha att sp�ket g�r tillbaka!
		return 0;
	}
	else
		return 5; // 5 points
}

void KillGhost::AddEntity(Entity entity)
{
	//mGhost = entity;
}
