#include "PowerPacman.h"


PowerPacman::PowerPacman(Pacman* pacman, vector<Ghost*>* ghosts) : Effect (500)
{
	mPacman = pacman;
	mAffectedGhosts = ghosts;
}
PowerPacman::~PowerPacman(void)
{
	//delete mAffectedGhosts;
	delete mPacman;
}
int PowerPacman::Run()
{
	int TimeLeft(Tick());
	if (TimeLeft == GetMaxTime()-1)
	{
		Behaviour *newBehaviour;
		for (uint i(0); i < mAffectedGhosts->size(); i++)
		{
			newBehaviour = new Scared(mPacman->GetPositionPointer(), new KillGhost((*mAffectedGhosts)[i]), (*mAffectedGhosts)[i]->GetDirection());
			(*mAffectedGhosts)[i]->ModifySpeed(-0.02f);
			((Ghost*)((*mAffectedGhosts)[i]))->SetBehaviour(newBehaviour);
			((Ghost*)((*mAffectedGhosts)[i]))->SetColour(vec3(0.3f,0.3f,0.3f));
		}
		//mPacman->ModifySpeed(0.02f);
		return 0;
	}
	else if (TimeLeft == 0)
	{
		for (uint i(0); i < mAffectedGhosts->size(); i++)
		{
			(*mAffectedGhosts)[i]->ModifySpeed(0);
			((Ghost*)((*mAffectedGhosts)[i]))->SetDefaultBehaviour();
		}
		//mPacman->ModifySpeed(0);
		return 5; //5 points
	}
	else if (TimeLeft > 0)
	{
		int count(TimeLeft%8);
		vec3 colour(0.3f,0.3f,0.3f);
		vec3 colour2(1,1,1);
		if (count == 0)
		for (uint i(0); i < mAffectedGhosts->size(); i++)
		{
			if ((*mAffectedGhosts)[i]->GetColor() == colour)
			{
				(*mAffectedGhosts)[i]->SetColour(colour2);
			}
			else if ((*mAffectedGhosts)[i]->GetColor() == colour2)
			{
				(*mAffectedGhosts)[i]->SetColour(colour);
			}
		}
	}
	return 0;
}
void PowerPacman::AddEntity(Entity *entit)
{
	
}
void PowerPacman::AddPacman(Pacman *pac)
{
	mPacman = pac;
}