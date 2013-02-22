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
		//Ghost.ReSpawn(); // ändra här! om vi ska ha att spöket går tillbaka!
		return 0;
	}
	else
		return 5; // 5 points
}

void KillGhost::AddEntity(Entity entity)
{
	//mGhost = entity;
}
