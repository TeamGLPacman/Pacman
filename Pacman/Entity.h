#ifndef ENTITY_H_
#define ENTITY_H_

#include "Object3D.h"
class Entity : public Object3D
{
private:
	vec3 mSpawnPosition;
	float mSpeed;
	float mModSpeed;
	
protected:
	vec3 mDirection;
	vec3 mTargetPoint;
	vec3 mNextDirection;

	void SetSpeed(float speed) 
		{ mSpeed = speed; }
	void SetDirection(vec3 direction)
		{ mDirection = direction;}
	void SetSpawnPosition(vec3 spawnPos)
		{ mSpawnPosition = spawnPos; }
	float GetModSpeed()
		{ return mModSpeed; }
public:
	//Entity(float speed, vec3 direction);

	Entity( float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size );

	Entity(void);
	~Entity(void);
	void ModifySpeed(float mod)
		{mModSpeed = mod; }
	float GetSpeed()
		{ return mSpeed + mModSpeed; }
	vec3 GetDirection()
		{ return mDirection; }
	vec3* GetPositionPointer()
	{
		return &mWorldPos;
	}
	
	virtual int Update(int*);
	
	void ReSpawn();
	void UpdateTargetPoint(bool canMove[4]);
	bool Collision(Object3D* obj, float dist);
};

#endif
