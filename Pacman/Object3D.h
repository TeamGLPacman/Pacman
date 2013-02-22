#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "CommonIncludes.h"

class Object3D
{
protected:
	void SetWorldPos( vec3 pos );
	void SetColour( vec3 colour );

public:
	Object3D();
	Object3D( uint modelID, uint textureID, uint shaderID, vec3 worldPos, float scale );
	~Object3D();

	
	vec3 GetWorldPos();
	vec3 GetColor();
private:
	uint mModelID;
	uint mTextureID;
	uint mShaderID;
	vec3 mWorldPos;
	vec3 mColour;
	float mScale;
};

#endif