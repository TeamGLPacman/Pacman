#include "Pacman.h"

// beh�ver inte finnas vi kan anv�nda oss av typ en enum
//#ifndef EASYLRUP
//#define UP 0
//#define RIGHT 1
//#define DOWN 2
//#define LEFT 3
//#endif

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

Pacman::Pacman( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size ) : 
	Entity( speed, direction, modelID, textureID, shaderID, worldPos, size )
{
	SetWorldPos(worldPos);
	SetSpawnPosition(worldPos);
	mNextDirection = FORWARD;
}

vec2 Pacman::GetGridPosition()
{
	vec2 returnValue;
	if ( floor(GetWorldPos().x) == floor(GetWorldPos().x+0.5f))
		returnValue.x = floor(GetWorldPos().x);
	else 
		returnValue.x = floor(GetWorldPos().x+1);
	if ( floor(GetWorldPos().z) == floor(GetWorldPos().z+0.5f))
		returnValue.y = floor(GetWorldPos().z);
	else 
		returnValue.y = floor(GetWorldPos().z+1);
	return returnValue;
}

int Pacman::Update(int* surroundings)
{
	SetWorldPos(GetWorldPos() + mDirection*0.05f);
	// Up, Right, Down, Left (Clockwise)
	InputHandler(); // added

	if(mNextDirection == BACKWARD)
	{
		mDirection *= -1;
		mNextDirection = FORWARD;
	}
	if(mNextDirection == RIGHT)
	{
		mDirection = glm::cross(mDirection, vec3(0,1,0));
		mNextDirection = FORWARD;
	}
	if(mNextDirection == LEFT)
	{
		mDirection = glm::cross(mDirection, vec3(0,1,0));
		mDirection *= -1;
		mNextDirection = FORWARD;
	}

	if ((surroundings[0] != 1 || surroundings[2] != 1) 
		&& (surroundings[1] != 1 || surroundings[3] != 1))
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
	if(GetAsyncKeyState('L') != 0)
	{
		mNextDirection = RIGHT;
	}

	else if(GetAsyncKeyState('J') != 0)
	{
		mNextDirection = LEFT;
	}

	else if(GetAsyncKeyState('K') != 0)
	{
		mNextDirection = BACKWARD;
	}



	// ta hand om input h�r
	// och uppdatera mNextDirection
}