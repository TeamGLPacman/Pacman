#ifndef POINTS_H_
#define POINTS_H_

#include "Effect.h"

class Points : public Effect
{
private:
	int mPoints;
public:
	Points();
	~Points();
	Points(int);

	int Run();


};
#endif