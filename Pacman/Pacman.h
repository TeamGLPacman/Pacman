#ifndef PACMAN_H_
#define PACMAN_H_
#include "CommonIncludes.h"
#include "Entity.h"

class Pacman : public Entity
{
private:
	vec3 mNextDirection;
	int mLives;

	void InputHandler();
	float mInputTimer;
public:
	Pacman();
	~Pacman();

	Pacman(float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size);

	vec2 GetGridPosition();

	int Update(int surroundings[4]);

	//Converts a vector to one of four int values (1=up, 2=right, 3=down, 4= left)
	int GetVecInt(vec3 theVec3);
};

#endif
