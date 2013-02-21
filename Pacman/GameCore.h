#ifndef GAMECORE_H_
#define GAMECORE_H_
#include "CommonIncludes.h"
#include <vector>


class GameCore
{
private:
	LogicGraphicsBridge mBridge;
	vector<Candy> mCandyList;
	vector<Ghost> mGhostList;
	vector<Effect> mEffects;
	vector<SoundSource> mSoundList;
	Level mLevel;
	Pacman mPacman;
	Light mLight;
	int mPoints;

	void Initialize();
	void Update();

	void CheckCollision();
	void PacmanCollisionCandy(); // ADDED!
	void GhostCollisionPacman(); // ADDED!

	void RenderObjects();
	
	uint SendBoxVertices();
	uint SendPoint();
	uint SendGroundVertices();

public:

	int GameLoop();
};












#endif