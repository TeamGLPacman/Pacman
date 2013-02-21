#ifndef VAOMODELLOADER_H_
#define VAOMODELLOADER_H_
#include "CommonIncludes.h"
#include "BaseStructures.h"

class VAOModelLoader
{
public:
	VAOModelLoader(void);
	~VAOModelLoader(void);

	unsigned int CreateModel(vector<VertexPoint> vertexList); 
	unsigned int CreateModel(vec3 position); 

};
#endif

