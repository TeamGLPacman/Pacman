#include "KillPacman.h"


KillPacman::KillPacman(void)
{
}


KillPacman::~KillPacman(void)
{
}
int KillPacman::Run()
{
	const char* s = typeid(Ghost()).name();
	const char* s1 = typeid(Pacman()).name();
	int timeLeft = Tick();
	for (int i = 0; i < mEnties.size(); i++)
	{
		mEnties[i].ReSpawn();

		if (s == typeid(mEnties[i]).name())
		{
			// vad ska hända med Ghost objekt
		}
		else if (s1 == typeid(mEnties[i]).name())
		{
			// vad ska hända med pacman?
		}
	}
		
		
}

void KillPacman::AddEntity(Entity entity)
{
	mEnties.push_back(entity);
}