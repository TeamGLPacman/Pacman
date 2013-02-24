#include "Pacman.h"

// behöver inte finnas vi kan använda oss av typ en enum
#ifndef EASYLRUP
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#endif

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

Pacman::Pacman(vec3 position, float speed)
{
	SetSpeed(speed);
	SetWorldPos(position);
}

int Pacman::Update(int* surrondings)
{
	// Up, Right, Down, Left (Clockwise)
	InputHandler(); // added
	if ((surrondings[UP] == 1 || surrondings[DOWN] == 1) 
		&& (surrondings[RIGHT] == 1 || surrondings[LEFT] == 1))
	{
		// pacman kan nu svänga!
		// eftersom!
		/* Up och ner (kräver inte att vi kollar i buffern
			|
			P
			|
		Så oavsätt om vi kan gå upp och ner eller ner/upp betyder det att vi inte behöver ändra riktning
		vi kommer enbart behöva ändra när man kan svänga i 90 grader
		*/
	}
	return 0;
}

void Pacman::InputHandler()
{
	// ta hand om input här
	// och uppdatera mNextDirection
}