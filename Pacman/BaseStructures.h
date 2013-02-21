#ifndef BASESTRUCTURES_H_
#define BASESTRUCTURES_H_
#include "Object3D.h"
#include "CommonIncludes.h"

struct VertexPoint
{
	vec3 mPosition;
	vec3 mNormal;
	vec2 mTexCoord;

	VertexPoint(vec3 pos, vec3 norm, vec2 texCoord)
	{
		mPosition = pos;
		mNormal = norm;
		mTexCoord = texCoord;
	}
};

#endif