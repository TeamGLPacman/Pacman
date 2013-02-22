#include "PowerPacman.h"


PowerPacman::PowerPacman(void) : Effect (500)
{
}
PowerPacman::~PowerPacman(void)
{
}
int PowerPacman::Run()
{
	// För optimering krävs en extra variabel !
	int TimeLeft = Tick();
	if (TimeLeft == GetMaxTime()-1)
	{
		for (int i = 0; i < mAffectedGhosts.size(); i++)
			mAffectedGhosts[i].SetBehaviour(Scared());
		mPacman.ModifySpeed(2);
		return 0;
	}
	else if (TimeLeft <= 0)
	{
		for (int i = 0; i < mAffectedGhosts.size(); i++)
			mAffectedGhosts[i].SetDefaultBehaviour();
		mPacman.ModifySpeed(0);
		return 5; //5 points
	}
}

void PowerPacman::AddEntity(Entity ghost)
{
	mAffectedGhosts.push_back(ghost);
}