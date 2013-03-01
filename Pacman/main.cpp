#include "GameCore.h"
#include <iostream>


int main( int argc, char** argv )
{
	GameCore mGameCore;
	mGameCore.Initialize( argc, argv );
	return mGameCore.GameLoop();
}