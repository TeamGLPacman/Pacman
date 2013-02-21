#ifndef LEVEL_H_
#define LEVEL_H_
#include "CommonIncludes.h"

class Level
{
public:
	Level(void);
	~Level(void);
	int** GetMapValues();
	int* GetSurroundingGrid( glm::vec2 );
	vector<vec3> GetBoxList();
	Object3D GetGround();

	void SetBoxHandles( uint modID, uint texID, uint shadID );

private:
	vector<vec3> mBoxList;
	Object3D mGround;
	int** mMapValues;


};

#endif