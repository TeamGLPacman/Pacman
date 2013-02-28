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
#include "Light.h"
#include "Behaviour.h"
#include "PowerPacman.h"
#include "KillPacman.h"
#include "Scared.h"


class GameCore
{
private:
	LogicGraphicsBridge mBridge;
	vector<Object3D*> mCandyList;
	vector<Ghost*> mGhostList;
	vector<Effect*> mEffects;
	//vector<SoundSource> mSoundList;
	Level mLevel;
	Pacman mPacman;
	Light mLight;
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
	GameCore();
	~GameCore();
	void Initialize( int argc, char** argv );
	int GameLoop();
};

#endif