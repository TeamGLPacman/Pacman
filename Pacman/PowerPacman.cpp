#include "PowerPacman.h"


PowerPacman::PowerPacman(void) : Effect (5000)
{
}
PowerPacman::~PowerPacman(void)
{
}
int PowerPacman::Run()
{
	int TimeLeft = Tick();
	Behaviour *newBehaviour;
	if (TimeLeft == GetMaxTime()-1)
	{
		for (int i = 0; i < mAffectedGhosts.size(); i++)
			mAffectedGhosts[i]->SetBehaviour(newBehaviour);
		mPacman->ModifySpeed(0.05);
		return 0;
	}
	else if (TimeLeft <= 0)
	{
		for (int i = 0; i < mAffectedGhosts.size(); i++)
			mAffectedGhosts[i]->SetDefaultBehaviour();
		mPacman->ModifySpeed(0);
		return 5; //5 points
	}
	return 0;
}

void PowerPacman::AddEntity(Entity *entit)
{
	//mAffectedGhosts.push_back(ghost);
}
void PowerPacman::AddPacman(Pacman *pac)
{
	mPacman = pac;
	//mAffectedGhosts.push_back(ghost);
}