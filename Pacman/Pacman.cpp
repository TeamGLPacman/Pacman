#include "Pacman.h"

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

int Pacman::Update()
{
	InputHandler(); // added
	// vi behöver SurroundingGrids!
	return 0;
}

void Pacman::InputHandler()
{
	// ta hand om input här
	// och uppdatera mNextDirection
}