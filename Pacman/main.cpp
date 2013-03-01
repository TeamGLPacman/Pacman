#include "GameCore.h"

int main( int argc, char** argv )
{
	GameCore mGameCore;
	mGameCore.Initialize( argc, argv );
	return mGameCore.GameLoop();
}