#include "Level.h"
#include <map>

Level::Level()
{ }

bool Level::LoadMap( const char* path )
{

	int handle, amount;

	int width, height, channels;

	unsigned char* map = SOIL_load_image( path, &width, &height, &channels, 1 );

	mWidth = width;
	mHeight = height;

	mMapValues = new int*[width];
	for( int i = 0; i < width; i++ )
		mMapValues[i] = new int[height];

	//Loop through image and assign id to each map position
	for( int y = 0; y < height; y++ )
	{
		for( int x = 0; x < width; x++ )
		{
			int id = 0;
			int value = map[x + (y * width)];
			
			if( value <= 10 )
				id = 1; //Box (Wall)
			else if( value <= 50 )
				id = 2; //Pacman
			else if( value <= 140 )
				id = 3; //Ghosts
			else if( value <= 200 )
				id = 4; //Special Candy
			else
				id = 0; //Air

			mMapValues[x][y] = id;
		}
	}
	
	return BuildLevel();
}

//GetGroundVerticies

Level::~Level()
{
	for( int i = 0; i < mWidth; i++ ) 
	{
		delete mMapValues[i];
	}
}



int* Level::GetSurroundingGrid( vec2 pos )
{
	int sGrid[4]; // Up, Right, Down, Left (Clockwise)

	int xPos = pos.x;
	int yPos = pos.y;

	if(xPos > 0 && xPos < mWidth && yPos - 1 > 0 && yPos - 1 < mHeight) //Up
		sGrid[0] = mMapValues[xPos][yPos - 1];
	else
		sGrid[0] = 1;

	if(xPos + 1 > 0 && xPos + 1 < mWidth && yPos > 0 && yPos < mHeight) //Right
		sGrid[1] = mMapValues[xPos + 1][yPos];
	else
		sGrid[1] = 1;

	if(xPos + 1 > 0 && xPos < mWidth && yPos + 1 > 0 && yPos + 1 < mHeight) //Down
		sGrid[2] = mMapValues[xPos][yPos + 1];
	else
		sGrid[2] = 1;


	if(xPos - 1 > 0 && xPos - 1  < mWidth && yPos > 0 && yPos < mHeight) //Left
		sGrid[3] = mMapValues[xPos - 1][yPos];
	else
		sGrid[3] = 1;

		return sGrid;
}

int** Level::GetMapValues()
{
	return mMapValues;
}

int Level::GetHeight()
{
	return mHeight;
}

int Level::GetWidth()
{
	return mWidth;
}

Object3D Level::GetWalls()
{
	return mBoxes;
}

Object3D Level::GetGround()
{
	return mGround;
}

vec3 Level::GetPacmanSpawn()
{
	return mPacmanSpawn;
}

vec3 Level::GetGhostSpawn()
{
	return mGhostSpawn;
}

vector<vec3> Level::GetCandyPosList()
{
	return mCandyPosList;
}

vector<VertexPoint> Level::GetGroundVertices()
{
	return mGroundVertices;
}

vector<VertexPoint> Level::GetBoxVertices()
{
	return mBoxVertices;
}

bool Level::BuildLevel()
{
	if(mWidth != 0)
	{
		for( int y = 0; y < mHeight; y++ )
		{
			for( int x = 0; x < mWidth; x++ )
			{
				int value = mMapValues[x][y];

				if( value == 0 )
					mCandyPosList.push_back(vec3(x, 0.5, y));
				if( value == 1 )
					AddBoxVertices(vec3(x, 0.5, y)); //mBoxList.push_back(new Object3D(modelID, textureID, shaderID, vec3(x, 0.5, y), 1.0));
				if( value == 2 )
					mPacmanSpawn = vec3(x, 0.5, y);
				if( value == 3 )
					mGhostSpawn = vec3(x, 0.5, y);

				
				if(value != 1)
					AddGroundVertices(vec3(x, 0.5, y));
			}
		}

		//mBoxes = Object3D(modelID, textureID, shaderID, vec3(0,0,0), 1.0);

		return true;
	}
	return false;
}

bool Level::CreateBoxes( uint modelID, uint textureID, uint shaderID )
{
	if(mWidth != 0)
	{
		mBoxes = Object3D(modelID, textureID, shaderID, vec3(0,0,0), 1.0);
		return true;
	}
	return false;
}

bool Level::CreateGround( uint modelID, uint textureID, uint shaderID )
{
	if(mWidth != 0)
	{
		mGround = Object3D(modelID, textureID, shaderID, vec3(0, 0, 0), 1.0);
		return true;
	}
	return false;
}


void Level::AddBoxVertices(vec3 pos)
{
	//vector<VertexPoint> verts;

	/*
	mBoxVertices.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,-1,0), vec2(0.666467,0.666467)));
	mBoxVertices.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(0,-1,0), vec2(0.333533,0.666467)));
	mBoxVertices.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(0,-1,0), vec2(0.333533,0.333533)));

	mBoxVertices.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,-1,0), vec2(0.666467,0.333533)));
	mBoxVertices.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,-1,0), vec2(0.666467,0.666467)));
	mBoxVertices.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(0,-1,0), vec2(0.333533,0.333533)));
	*/

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,-0.5), vec3(-0,1,0), vec2(0.333134,0.333133)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,-0.5), vec3(-0,1,0), vec2(0.0002,0.333134)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,0.5), vec3(-0,1,0), vec2(0.0002,0.0002)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,0.5), vec3(-0,1,0), vec2(0.333133,0.0002)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,-0.5), vec3(-0,1,0), vec2(0.333134,0.333133)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,0.5), vec3(-0,1,0), vec2(0.0002,0.0002)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,-0.5), vec3(1,-0,1e-006), vec2(0.666467,0.0002)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,-0.5), vec3(1,-0,1e-006), vec2(0.666467,0.333133)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,0.5), vec3(1,-0,1e-006), vec2(0.333533,0.333134)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,0.5), vec3(1,0,-0), vec2(0.333533,0.0002)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,-0.5), vec3(1,0,-0), vec2(0.666467,0.0002)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,0.5), vec3(1,0,-0), vec2(0.333533,0.333134)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,0.5), vec3(-0,-0,1), vec2(0.9998,0.333533)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,0.5), vec3(-0,-0,1), vec2(0.9998,0.666467)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,0.5), vec3(-0,-0,1), vec2(0.666867,0.333533)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,0.5), vec3(-0,-0,1), vec2(0.9998,0.666467)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,0.5), vec3(-0,-0,1), vec2(0.666867,0.666467)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,0.5), vec3(-0,-0,1), vec2(0.666867,0.333533)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,0.5), vec3(-1,-0,-0), vec2(0.0002,0.9998)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,0.5), vec3(-1,-0,-0), vec2(0.0002,0.666867)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,-0.5), vec3(-1,-0,-0), vec2(0.333134,0.9998)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,0.5), vec3(-1,-0,-0), vec2(0.0002,0.666867)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,-0.5), vec3(-1,-0,-0), vec2(0.333134,0.666867)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,-0.5), vec3(-1,-0,-0), vec2(0.333134,0.9998)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,-0.5), vec3(0,0,-1), vec2(0.333134,0.333533)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,-0.5), vec3(0,0,-1), vec2(0.333134,0.666467)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,-0.5), vec3(0,0,-1), vec2(0.0002,0.666467)));

	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,0.5,-0.5), vec3(0,0,-1), vec2(0.0002,0.333533)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(0.5,0.5,-0.5), vec3(0,0,-1), vec2(0.333134,0.333533)));
	mBoxVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,-0.5), vec3(0,0,-1), vec2(0.0002,0.666467)));

}


void Level::AddGroundVertices(vec3 pos)
{
	mGroundVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,-0.5), vec3(-0,1,0), vec2(0.333134,0.333133)));
	mGroundVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,-0.5), vec3(-0,1,0), vec2(0.0002,0.333134)));
	mGroundVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,0.5), vec3(-0,1,0), vec2(0.0002,0.0002)));

	mGroundVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,0.5), vec3(-0,1,0), vec2(0.333133,0.0002)));
	mGroundVertices.push_back(VertexPoint(pos + vec3(0.5,-0.5,-0.5), vec3(-0,1,0), vec2(0.333134,0.333133)));
	mGroundVertices.push_back(VertexPoint(pos + vec3(-0.5,-0.5,0.5), vec3(-0,1,0), vec2(0.0002,0.0002)));
}