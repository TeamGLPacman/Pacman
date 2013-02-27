#ifndef LIGHT_H_
#define LIGHT_H_
#include "CommonIncludes.h"

class Light
{
private:
	vec3 mWorldPosition;
	float mRange;
	vec3 mDiffuse;
	vec3 mSpecular;
	uint mShaderID;
public:
	Light(vec3 pos, float range, vec3 diff, vec3 spec, uint shaderID);
	Light();
	~Light();
	vec3 GetPosition();
	vec3 GetDiffuse();
	vec3 GetSpecular();
	void SetPosition(vec3 pos);
	uint GetShaderID();
	float GetRange();
};

#endif

