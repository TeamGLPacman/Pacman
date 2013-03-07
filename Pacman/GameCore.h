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
#include "KillGhost.h"
#include "Scared.h"
#include "Hunt.h"
#include "SoundHandler.h"
#include "SoundSource.h"
#include <time.h>
#include <typeinfo>

class GameCore
{
private:
	LogicGraphicsBridge mBridge;
	vector<Object3D*> mCandyList;
	vector<Ghost*> mGhostList;
	vector<Effect*> mEffects;
	vector<SoundSource> mSoundList;
	vector<SoundSource> mGhostSounds;

	SoundHandler mSoundHandler;
	SoundSource mMusicSound, mPowerPacmanSound, mEatSound, mDeathSound, mEatGhostSound;
	
	Level mLevel;
	Pacman mPacman;
	Light mLight;
	int mPoints;
	int mCantMove;
	bool mSoundsStarted;

	bool PowerCandyCheck(int i);
	void Update();
	void UpdateGhost();
	void UpdatePacman();
	void UpdateEffects();
	void UpdateSounds();
	void UpdateCamera();
	void CheckCollision();
	void PacmanCollisionCandy(); // ADDED!
	void GhostCollisionPacman(); // ADDED!
	bool StillRunning();
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