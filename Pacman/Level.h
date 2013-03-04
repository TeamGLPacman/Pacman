#ifndef LEVEL_H_
#define LEVEL_H_
#include "CommonIncludes.h"
#include "BaseStructures.h"
#include "Object3D.h"
#include "SOIL.h"

class Level
{
public:
	Level( );
	~Level();

	//Loads the level and all vertexpoints
	bool LoadMap( const char* path );

	bool CreateGround ( uint modID, uint texID, uint shadID );
	bool CreateWalls ( uint modID, uint texID, uint shadID );

	int** GetMapValues();
	int* GetSurroundingGrid(glm::vec2);

	Object3D GetWalls();
	Object3D GetGround();

	vector<VertexPoint> GetGroundVertices();
	vector<VertexPoint> GetWallVertices();

	vec3 GetPacmanSpawn();
	vec3 GetGhostSpawn();
	vector<vec3> GetCandyPosList();
	vector<vec3> GetSpecCandyPosList();

	int GetHeight();
	int GetWidth();

private:
	int mWidth, mHeight;

	vec3 mPacmanSpawn, mGhostSpawn;
	vector<vec3> mCandyPosList;
	vector<vec3> mSpecCandyPosList;

	vector<VertexPoint> mGroundVertices;
	vector<VertexPoint> mWallVertices;

	Object3D mWalls;
	Object3D mGround;
	int** mMapValues;

	bool BuildLevel();

	void AddWallVertices( vec3 pos );
	void AddGroundVertices( vec3 pos );

};

#endif