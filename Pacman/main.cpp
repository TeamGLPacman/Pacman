#include "GameCore.h"

GameCore mGameCore;

int main( int argc, char** argv )
{
	mGameCore.Initialize( argc, argv );
	return mGameCore.GameLoop();
}