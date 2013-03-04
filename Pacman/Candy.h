#ifndef CANDY_H_
#define CANDY_H_
#include "CommonIncludes.h"
#include "Points.h"
#include "Object3D.h"

class Candy : public Object3D
{
public:
	Candy( uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size);
	Effect* GetEffect();
private:
	Effect* mEffect;

};


#endif