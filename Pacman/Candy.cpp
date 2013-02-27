#include "Candy.h"

Candy::Candy(uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size) : 
	Object3D( modelID, textureID, shaderID, worldPos, size )
{
	mEffect = new Points(10);
}

Effect* Candy::GetEffect()
{
	return mEffect;
}