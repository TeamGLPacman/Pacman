#include "Candy.h"

Candy::Candy(uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size, Effect* effect) : 
	Object3D( modelID, textureID, shaderID, colour, worldPos, size )
{
	mEffect = effect;
}
Candy::~Candy()
{
	delete mEffect;
}
Effect* Candy::GetEffect()
{
	return mEffect;
}