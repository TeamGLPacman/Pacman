#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "CommonIncludes.h"

class Object3D
{
public:
	Object3D( uint modelID, uint textureID, uint shaderID, vec3 worldPos );
	~Object3D();

	uint GetModelID();
	uint GetTextureID();
	uint GetShaderID();

	vec3 GetWorldPos();
	vec3 GetColor();

	void SetWorldPos( vec3 pos );
	void SetColour( vec3 colour );

private:
	uint mModelID;
	uint mTextureID;
	uint mShaderID;
	vec3 mWorldPos;
	vec3 mColour;
	float mScale;
};

#endif