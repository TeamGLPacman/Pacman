#ifndef PACMAN_H_
#define PACMAN_H_
#include "CommonIncludes.h"
#include "Entity.h"

/*enum RelativeDirection
{
	FORWARD,
	RIGHT,
	BACKWARD,
	LEFT
};*/

class Pacman : public Entity
{
private:
	vec3 mNextDirection;
	int mLives;
	

	void InputHandler(int[4]);
	float mInputTimer;
public:
	Pacman();
	~Pacman();

	Pacman(float speed, vec3 direction, uint modelID, uint textureID, uint shaderID, vec3 worldPos, float size);

	vec2 GetGridPosition();

	int Update(int [4]);


};

#endif