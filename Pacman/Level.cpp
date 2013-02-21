#include "Level.h"
#include "SOIL.h"


Level::Level()
{ }

bool Level::LoadMap( const char* path, int width, int height )
{
	int mWidth = width;
	int mHeight = height;

	int **mMapValues = new int*[width];
	for( int i = 0; i < width; i++ )
		mMapValues[i] = new int[height];

	int channels = 1;
	unsigned char* map = SOIL_load_image( path, &width, &height, &channels, 1 );

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

}

Level::~Level()
{
	for( int y = 0; y < mHeight; y++ )
	{
		for( int x = 0; x < mWidth; x++ )
		{
			delete &mMapValues[x][y];
		}
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
		sGrid[0] = mMapValues[xPos + 1][yPos];
	else
		sGrid[0] = 1;

	if(xPos + 1 > 0 && xPos < mWidth && yPos + 1 > 0 && yPos + 1 < mHeight) //Down
		sGrid[0] = mMapValues[xPos][yPos + 1];
	else
		sGrid[0] = 1;


	if(xPos - 1 > 0 && xPos - 1  < mWidth && yPos > 0 && yPos < mHeight) //Left
		sGrid[0] = mMapValues[xPos - 1][yPos];
	else
		sGrid[0] = 1;

		return sGrid;
}

int** Level::GetMapValues()
{
	return mMapValues;
}

vector<Object3D> Level::GetBoxList()
{

}

void Level::SetBoxHandles( uint modelID, uint textureID, uint shaderID )
{

}