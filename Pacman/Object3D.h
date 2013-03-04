#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "CommonIncludes.h"

class Object3D
{
protected:
	void SetWorldPos( vec3 pos );
	void SetColour( vec3 colour );
	vec3 mWorldPos;
public:
	Object3D( uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size );
	Object3D();
	~Object3D();

	uint GetModelID();
	uint GetTextureID();
	uint GetShaderID();
	
	vec3 GetWorldPos();
	vec3 GetColor();

	float GetSize();

private:
	uint mModelID;
	uint mTextureID;
	uint mShaderID;
	
	vec3 mColour;
	float mSize;
};

#endif