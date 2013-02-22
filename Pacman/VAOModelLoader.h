#ifndef VAOMODELLOADER_H_
#define VAOMODELLOADER_H_
#include "CommonIncludes.h"
#include "BaseStructures.h"
#include <map>

class VAOModelLoader
{
public:
	map<uint, int> mModelVertexCount;  //holds modelID and how many vertices

	VAOModelLoader(void);
	~VAOModelLoader(void);

	uint CreateModel(vector<VertexPoint> vertexList); 
	uint CreateModel(vec3 position); 

};
#endif

