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
	bool LoadMap( const char* path, int width, int height );
	int** GetMapValues();
	int* GetSurroundingGrid( glm::vec2 );
	vector<Object3D> GetBoxList();
	Object3D GetGround();

	void SetBoxHandles( uint modID, uint texID, uint shadID );

private:
	int mWidth, mHeight;

	vector<Object3D> mBoxList;
	Object3D mGround;
	int** mMapValues;


};

#endif