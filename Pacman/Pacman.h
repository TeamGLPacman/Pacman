#include "Pacman.h"

Pacman::Pacman()
{
}
Pacman::Pacman(vec3 position, float speed)
{
	SetSpeed(speed);
	SetWorldPos(position);
}

int Pacman::Update()
{
	InputHandler() // added
	// vi beh�ver SurroundingGrids!
}

void Pacman::InputHandler()
{
	// ta hand om input h�r
	// och uppdatera mNextDirection
}