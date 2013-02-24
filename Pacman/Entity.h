#ifndef ENTITY_H_
#define ENTITY_H_

#include "Object3D.h"
class Entity : public Object3D
{
private:
	float mModSpeed;
	float mSpeed;
	vec3 mDirection;
protected:
	void SetSpeed(float speed) 
		{ mSpeed = speed; }
	void SetDirection(vec3 direction)
		{ mDirection = direction;}
public:
	Entity(float, vec3);
	Entity(void);
	~Entity(void);
	void ModifySpeed(float mod)
		{mModSpeed = mod; }
	float GetSpeed()
		{ return mSpeed; }
	vec3 GetDirection()
		{ return mDirection; }
	vec3 mSpawnPosition;
	// vec3 ??"#)"
	vec3 mTargetPoint;

	virtual int Update();
	void ReSpawn();
	void UpdateTargetPoint(bool canMove[4]);
	bool Collision(Object3D obj, float dist);
};

#endif
