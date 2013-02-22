#ifndef GAMECORE_H_
#define GAMECORE_H_
#include "CommonIncludes.h"
#include "BaseStructures.h"
#include "Level.h"
#include "LogicGraphicsBridge.h"
#include "Effect.h"
#include "Candy.h"
#include "Ghost.h"
#include "Pacman.h"


class GameCore
{
private:
	LogicGraphicsBridge mBridge;
	vector<Candy> mCandyList;
	vector<Ghost> mGhostList;
	vector<Effect> mEffects;
	//vector<SoundSource> mSoundList;
	Level mLevel;
	Pacman mPacman;
	//Light mLight;
	int mPoints;


	void Update();

	void CheckCollision();
	void PacmanCollisionCandy(); // ADDED!
	void GhostCollisionPacman(); // ADDED!

	void RenderObjects();
	
	uint SendBoxVertices();
	uint SendPoint();
	uint SendGroundVertices();

public:

	void Initialize( int argc, char** argv );
	int GameLoop();
};












#endif