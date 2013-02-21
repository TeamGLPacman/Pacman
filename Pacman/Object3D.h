#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "CommonIncludes.h"

class Object3D
{
public:
	Object3D(void);
	~Object3D(void);

	unsigned int GetModelID();
	unsigned int GetTextureID();
	unsigned int GetShaderID(); 

	vec3 GetWorldPos();
	vec3 GetColor();

	void SetWorldPos( vec3 pos );
	void SetColour( vec3 colour );

private:
	unsigned int mModelID;
	unsigned int mTextureID;
	unsigned int mShaderID;
	vec3 mWorldPos;
	vec3 mColour;
	float mScale;
};

#endif