#ifndef LEVEL_H_
#define LEVEL_H_
#include "CommonIncludes.h"
#include "Object3D.h"
#include "SOIL.h"

class Level
{
public:
	Level( );
	~Level();
	bool LoadMap( const char* path );
	bool BuildBoxes( uint modID, uint texID, uint shadID );
	bool BuildGround ( uint modID, uint texID, uint shadID );

	int** GetMapValues();
	int* GetSurroundingGrid(glm::vec2);
	vector<Object3D> GetBoxList();
	Object3D GetGround();

	vec3 GetPacmanSpawn();
	vec3 GetGhostSpawn();

	int GetHeight();
	int GetWidth();

private:
	int mWidth, mHeight;

	vec3 mPacmanSpawn, mGhostSpawn;

	vector<Object3D> mBoxList;
	Object3D mGround;
	int** mMapValues;


};

#endif