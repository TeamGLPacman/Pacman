#ifndef GHOST_H_
#define GHOST_H_

#include "CommonIncludes.h"
#include "Entity.h"
#include "Effect.h"
#include "Behaviour.h"

class Ghost : public Entity
{
public:
	Ghost(float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 colour, vec3 worldPos, float size, Behaviour *behaviour);
	~Ghost();
	int Update(int sur[4]);

	vec2 GetGridPos();

	void SetDefaultBehaviour()
		{ mBehaviour = mDefualtBehaviour; }
	void SetBehaviour(Behaviour *set)
		{ 
			mBehaviour = set; 
		}
	Effect* GetEffect()
		{ return mBehaviour->GetEffect(); }

private:

	Behaviour *mBehaviour;
	Behaviour *mDefualtBehaviour;
};


#endif