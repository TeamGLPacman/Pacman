#ifndef POINTS_H_
#define POINTS_H_
#include "Effect.h"
class Points : public Effect
{
private:
	mPoints;
public:
	Points();
	Points(int);

	int Run();

	~Points();
};
#endif