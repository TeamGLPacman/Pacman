#ifndef ENTITY_H_
#define ENTITY_H_

#include "Object3D.h"
class Entity : Object3D
{
public:
	Entity();
	~Entity();

	//vec3 mSpawnPosition;
	float mSpeed;
	vec3 mDirection; // vec3 ??"#)"
	//vec3 mTargetPoint;

	virtual int Update();
	void ReSpawn();
	void UpdateTargetPoint(bool canMove[4]);
	bool Collision(Object3D obj, float dist);
};

#endif
