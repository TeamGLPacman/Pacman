#pragma once
#include "Object3D.h"
class Entity
{
public:
	Entity(void);
	~Entity(void);

	//vec3 mSpawnPosition;
	float mSpeed;
	//vec3 mTargetPoint;

	virtual int Update();
	void ReSpawn();
	void UpdateTargetPoint(bool canMove[4]);
	bool Collision(Object3D obj, float dist);
};

