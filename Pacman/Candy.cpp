#include "Candy.h"

Candy::Candy(uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size) : 
	Object3D( modelID, textureID, shaderID, colour, worldPos, size )
{
	mEffect = new Points(10);
}

Effect* Candy::GetEffect()
{
	return mEffect;
}