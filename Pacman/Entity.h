#ifndef ENTITY_H_
#define ENTITY_H_

#include "Object3D.h"
class Entity : public Object3D
{
private:
	vec3 mSpawnPosition;
	float mSpeed;
	float mModSpeed;
	vec3 mTargetPoint;
	vec3 mDirection;
protected:
	void SetSpeed(float speed) 
		{ mSpeed = speed; }
	void SetDirection(vec3 direction)
		{ mDirection = direction;}
	void SetSpawnPosition(vec3 spawnPos)
		{ mSpawnPosition = spawnPos; }
public:
	//Entity(float speed, vec3 direction);

	Entity( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size );

	Entity(void);
	~Entity(void);
	void ModifySpeed(float mod)
		{mModSpeed = mod; }
	float GetSpeed()
		{ return mSpeed; }
	vec3 GetDirection()
		{ return mDirection; }
	
	virtual int Update(int*);
	
	void ReSpawn();
	void UpdateTargetPoint(bool canMove[4]);
	bool Collision(Object3D* obj, float dist);
};

#endif
