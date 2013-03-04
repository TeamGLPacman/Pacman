#include "Object3D.h"


Object3D::Object3D( uint modelID, uint textureID,  uint shaderID, vec3 colour, vec3 worldPos, float size )
{
	mModelID = modelID;
	mTextureID = textureID;
	mShaderID = shaderID;
	mWorldPos = worldPos;
	mSize = size;
	mColour = colour;
}

Object3D::Object3D()
{
}

Object3D::~Object3D()
{
}

unsigned int Object3D::GetModelID()
{
	return mModelID;
}

unsigned int Object3D::GetTextureID()
{
	return mTextureID;
}

unsigned int Object3D::GetShaderID()
{
	return mShaderID;
}

float Object3D::GetSize()
{
	return mSize;
}

vec3 Object3D::GetWorldPos()
{
	return mWorldPos;
}

vec3 Object3D::GetColor()
{
	return mColour;
}

void Object3D::SetWorldPos( vec3 pos )
{
	mWorldPos = pos;
}

void Object3D::SetColour( vec3 colour )
{
	mColour = colour;
}