#ifndef VAOMODELLOADER_H_
#define VAOMODELLOADER_H_
#include "CommonIncludes.h"
#include "BaseStructures.h"

class VAOModelLoader
{
public:
	VAOModelLoader(void);
	~VAOModelLoader(void);

	uint CreateModel(vector<VertexPoint> vertexList); 
	uint CreateModel(vec3 position); 

};
#endif

