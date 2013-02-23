#ifndef CANDY_H_
#define CANDY_H_
#include "CommonIncludes.h"
#include "Effect.h"
#include "Object3D.h"

class Candy : public Object3D
{
public:
	Candy();
	Effect GetEffect();
private:
	Effect mEffect;

};


#endif