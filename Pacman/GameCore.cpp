#include "GameCore.h"

int GameCore::GameLoop(){
	while(true){
		Update(); // Update Entitys
		CheckCollision(); // Checking Collisions
		RenderObjects(); // Draw Objects
		// if press esc exit(1);
	}
	return 0;
}

void GameCore::Initialize(){
	mBridge.Initialize();

	uint boxID = SendBoxVertices();
	uint groundID = SendGroundVertices();
	uint pointID = SendPoint();

	// SKAPA CANDY, GHOST, PACMAN OCH LEVEL
	
}

void GameCore::Update(){
	mPacman.Update();
	for (int i = 0; i < mGhostList.size(); i++)
		mGhostList[i].Update();
	for (int i = 0; i < mEffects.size(); i++)
		mEffects[i].Run();
}

void GameCore::CheckCollision(){
	PacmanCollisionCandy();
	GhostCollisionPacman();
}

void GameCore::PacmanCollisionCandy(){
	for (int i = 0; i < mCandyList.size(); i++)
	{
		if (mPacman.Collision(mCandyList[i]))
		{
			mEffects.push_back(mCandyList[i].GetEffect());
			mCandyList.erase(mCandyList.begin()+i); // remove candy
			break;
		}
	}
}

void GameCore::GhostCollisionPacman(){
	for(int i = 0; i < mGhostList.size(); i++)
	{
		if (mGhostList[i].Collision(mPacman))
		{
			mEffects.push_back(mGhostList[i].GetEffect());
			break;
		}
	}
}

void GameCore::RenderObjects(){
	mBridge.ClearScreen(); // ADDED!

	// Render Pacman
	mBridge.RenderObject(mPacman);
	// Render Candy
	for (int i = 0; i < mCandyList.size(); i++)
		mBridge.RenderObject(mCandyList[i]);
	// Render Ghost
	for (int i = 0; i < mGhostList.size(); i++)
		mBridge.RenderObject(mGhostList[i]);

	mBridge.RenderScreen(); // ADDED!
}
