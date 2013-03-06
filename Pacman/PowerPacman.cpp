#include "PowerPacman.h"


PowerPacman::PowerPacman(Pacman* pacman, vector<Ghost*>* ghosts) : Effect (500)
{
	mPacman = pacman;
	mAffectedGhosts = ghosts;
}
PowerPacman::~PowerPacman(void)
{
	delete mAffectedGhosts;
	delete mPacman;
}
int PowerPacman::Run()
{
	int TimeLeft = Tick();
	if (TimeLeft == GetMaxTime()-1)
	{
		Behaviour *newBehaviour;
		for (int i = 0; i < mAffectedGhosts->size(); i++)
		{
			newBehaviour = new Scared(mPacman->GetPositionPointer(), new KillGhost((*mAffectedGhosts)[i]));
			(*mAffectedGhosts)[i]->ModifySpeed(-0.02);
			((Ghost*)((*mAffectedGhosts)[i]))->SetBehaviour(newBehaviour);
		}
		mPacman->ModifySpeed(0.02);
		return 0;
	}
	else if (TimeLeft == 0)
	{
		for (int i = 0; i < mAffectedGhosts->size(); i++)
		{
			(*mAffectedGhosts)[i]->ModifySpeed(0);
			((Ghost*)((*mAffectedGhosts)[i]))->SetDefaultBehaviour();
		}
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