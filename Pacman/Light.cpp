#include "Light.h"


Light::Light(vec3 pos, float range, vec3 diff, vec3 spec, uint shaderID) 
	: mWorldPosition(pos), mRange(range), mDiffuse(diff), mSpecular(spec), mShaderID(shaderID)
{

}

Light::Light()
{
}

Light::~Light()
{
}

vec3 Light::GetPosition()
{
	return mWorldPosition;
}

vec3 Light::GetDiffuse()
{
	return mDiffuse;
}

vec3 Light::GetSpecular()
{
	return mSpecular;
}

void Light::SetPosition(vec3 pos)
{
	mWorldPosition = pos;
}

uint Light::GetShaderID()
{
	return mShaderID;
}

float Light::GetRange()
{
	return mRange;
}