#include "Pacman.h"

// behöver inte finnas vi kan använda oss av typ en enum
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
	mNextDirection = direction;
	mTargetPoint = worldPos + direction;
	mInputTimer = 0;
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
	//return vec2(mTargetPoint.x, mTargetPoint.z);
}

int GetVecInt(vec3 theVec3)
{
	vec3 vec = glm::normalize(theVec3);
	int i;

	if( vec == vec3(0,0,1) )
		i = 0;
	else if( vec == vec3(1,0,0) )
		i = 1;
	else if( vec == vec3(0,0,-1) )
		i = 2;
	else
		i = 3;

	return i;
}




int Pacman::Update(int surroundingGrid[4])
{
	float distX = GetWorldPos().x - mTargetPoint.x;
	float distZ = GetWorldPos().z - mTargetPoint.z;

	if(distX <= GetSpeed() && distX >= -GetSpeed() && distZ <= GetSpeed() && distZ >= -GetSpeed())
	{
		SetWorldPos(mTargetPoint);

		if(surroundingGrid[GetVecInt(mNextDirection)] != 1)
		{
			mTargetPoint += mNextDirection;
			mDirection = mNextDirection;
		}
		else if(surroundingGrid[GetVecInt(mDirection)] != 1)
		{
			mTargetPoint += mDirection;
		}
			else
				mTargetPoint = mTargetPoint;
	}
	else
		SetWorldPos(vec3(GetWorldPos() + mDirection * GetSpeed()));


	//if(GetWorldPos().x == mTargetPoint.x)

		/*
	if (mDirection.x == 1 && SurroundingGrid[1] != 1)
		SetWorldPos(GetWorldPos() + mDirection*0.05f);
	else if (mDirection.x == -1 && SurroundingGrid[3]  != 1)
		SetWorldPos(GetWorldPos() + mDirection*0.05f);
	else if (mDirection.z == 1 && SurroundingGrid[2]  != 1)
		SetWorldPos(GetWorldPos() + mDirection*0.05f);
	else if (mDirection.z == -1 && SurroundingGrid[0]  != 1)
		SetWorldPos(GetWorldPos() + mDirection*0.05f);
		*/
	// Up, Right, Down, Left (Clockwise)
	InputHandler(surroundingGrid); // added
	/*
	if(mNextDirection == BACKWARD)
	{
		mDirection *= -1;
		mNextDirection = FORWARD;
	}
	if(mNextDirection == RIGHT)
	{
		mDirection = glm::cross(mDirection, vec3(0,1,0));
	}
	if(mNextDirection == LEFT)
	{
		mDirection = glm::cross(mDirection, vec3(0,1,0));
		mDirection *= -1;
	}
	//mNextDirection = mDirection;
*//*
	if ((SurroundingGrid[0] != 1 || SurroundingGrid[2] != 1) 
		&& (SurroundingGrid[1] != 1 || SurroundingGrid[3] != 1))
	{
		// pacman kan nu svänga!
		// eftersom!
		 Up och ner (kräver inte att vi kollar i buffern
			|
			P
			|
		Så oavsätt om vi kan gå upp och ner eller ner/upp betyder det att vi inte behöver ändra riktning
		vi kommer enbart behöva ändra när man kan svänga i 90 grader
		
	}*/
	return 0;
}



void Pacman::InputHandler(int SurroundingGrid[4])
{
	// vec (1,0,0) höger
	// vec (-1,0,0) vänster
	// vec (0,0,-1) up
	// vec (0,0,1) ner
	vec2 GridPos = GetGridPosition();
	cout << SurroundingGrid[0] << " " << SurroundingGrid[1] << " " << SurroundingGrid[2] << " " << SurroundingGrid[3] << endl;
	/*
	if(GetAsyncKeyState('L') != 0)
	{
		if (GetDirection().x == 1 && level->GetSurroundingGrid(GridPos)[2] != 1)
			mNextDirection = RIGHT;
		else if (mDirection.x == -1 && level->GetSurroundingGrid(GridPos)[0] != 1)
			mNextDirection = RIGHT;
		else if (mDirection.z == -1 && level->GetSurroundingGrid(GridPos)[1] != 1)
			mNextDirection = RIGHT;
		else if (mDirection.z == 1 && level->GetSurroundingGrid(GridPos)[3] != 1)
			mNextDirection = RIGHT;
	}

	else if(GetAsyncKeyState('J') != 0)
	{
		if (mDirection.x == 1 && level->GetSurroundingGrid(GridPos)[0] != 1)
			mNextDirection = LEFT;
		else if (mDirection.x == -1 && level->GetSurroundingGrid(GridPos)[2] != 1)
			mNextDirection = LEFT;
		else if (mDirection.z == -1 && level->GetSurroundingGrid(GridPos)[3] != 1)
			mNextDirection = LEFT;
		else if (mDirection.z == 1 && level->GetSurroundingGrid(GridPos)[1] != 1)
			mNextDirection = LEFT;
	}
	*/
	if(mInputTimer > 1)
	{
		if(GetAsyncKeyState('L') != 0)
		{
			mNextDirection =  glm::cross(mDirection, vec3(0,1,0));
			mInputTimer = 0;
		}
		else if(GetAsyncKeyState('J') != 0)
		{
			mNextDirection = -glm::cross(mDirection, vec3(0,1,0));
			mInputTimer = 0;
		}
		else if(GetAsyncKeyState('K') != 0)
		{
			mNextDirection *= -1;
			mInputTimer = 0;
		}
	}
	mInputTimer+= 0.01;



	// ta hand om input här
	// och uppdatera mNextDirection
}