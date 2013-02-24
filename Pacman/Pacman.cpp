#include "Pacman.h"

// beh�ver inte finnas vi kan anv�nda oss av typ en enum
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
		// pacman kan nu sv�nga!
		// eftersom!
		/* Up och ner (kr�ver inte att vi kollar i buffern
			|
			P
			|
		S� oavs�tt om vi kan g� upp och ner eller ner/upp betyder det att vi inte beh�ver �ndra riktning
		vi kommer enbart beh�va �ndra n�r man kan sv�nga i 90 grader
		*/
	}
	return 0;
}

void Pacman::InputHandler()
{
	// ta hand om input h�r
	// och uppdatera mNextDirection
}