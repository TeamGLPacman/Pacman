#pragma once
class Object3D
{
public:
	Object3D(void);
	~Object3D(void);

	unsigned int mModelID;
	unsigned int mTextureID;
	unsigned int mShaderID;
	//vec3 mWorldPos;
	//vec3 mColour;
	float mScale;

	unsigned int GetModelID();
	unsigned int GetTextureID();
	unsigned int GetShaderID();
	//vec3 GetWorldPos();
	//vec3 GetColor();
};

