#ifndef PACMAN_H_
#define PACMAN_H_
#include "CommonIncludes.h"
#include "Entity.h"

enum RelativeDirection
{
	FORWARD,
	RIGHT,
	BACKWARD,
	LEFT
};

class Pacman : public Entity
{
private:
	RelativeDirection mNextDirection;
	int mLives;
public:
	Pacman();
	Pacman(vec3, float);

	int Update();

	~Pacman();
};

#endif