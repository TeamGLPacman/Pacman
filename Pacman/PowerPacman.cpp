#include "PowerPacman.h"


PowerPacman::PowerPacman(void) : Effect (10000)
{
}
PowerPacman::~PowerPacman(void)
{
}
int PowerPacman::Run()
{
	int TimeLeft = Tick();
	if (TimeLeft == GetMaxTime()-1)
	{
		Behaviour *newBehaviour;
		for (int i = 0; i < mAffectedGhosts.size(); i++)
			((Ghost*)(mAffectedGhosts[i]))->SetBehaviour(newBehaviour);
		mPacman->ModifySpeed(0.05);
		return 0;
	}
	else if (TimeLeft <= 0)
	{
		for (int i = 0; i < mAffectedGhosts.size(); i++)
			((Ghost*)(mAffectedGhosts[i]))->SetDefaultBehaviour();
		mPacman->ModifySpeed(0);
		return 5; //5 points
	}
	return 0;
}
//void PowerPacman::AddGhost(Ghost *ghost)
//{
	
//}
void PowerPacman::AddEntity(Entity *entit)
{
	
}
void PowerPacman::AddPacman(Pacman *pac)
{
	mPacman = pac;
}