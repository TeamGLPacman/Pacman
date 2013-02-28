#include "GameCore.h"
#include <time.h>

GameCore::GameCore()
{
}

void wait ( float seconds )
{
 clock_t endwait;
 endwait = clock () + seconds * CLOCKS_PER_SEC ;
 while (clock() < endwait) {}
}

int GameCore::GameLoop(){
	while(true){
		Update(); // Update Entities
		CheckCollision(); // Checking Collisions
		RenderObjects(); // Draw Objects

		if(GetAsyncKeyState(VK_ESCAPE) != 0)
			return 0;
		wait(0.01f);
	}
	return 0;
}

void GameCore::Initialize( int argc, char** argv ){
	uint test = mBridge.Initialize( argc, argv );


	// SKAPA CANDY, GHOST, PACMAN OCH LEVEL
	
	
	uint shaderID = mBridge.LoadShaderFiles("../Shaders/shader.vertex", "../Shaders/shader.fragment");
	uint billboardShaderID = mBridge.LoadShaderFiles("../Shaders/billboardShader.vertex", "../Shaders/billboardShader.fragment", "../Shaders/billboardShader.geometry" );

	uint textureBoxID = mBridge.LoadTexture("../Textures/Wall.png");
	uint textureGroundID = mBridge.LoadTexture("../Textures/Floor.png");
	uint texturePacmanID = mBridge.LoadTexture("../Textures/Pacman.png");
	uint textureCandyID = mBridge.LoadTexture("../Textures/Candy.png");



	mLevel.LoadMap("../Maps/map001.png");

	uint boxID = mBridge.SendModel(mLevel.GetBoxVertices());
	uint groundID = mBridge.SendModel(mLevel.GetGroundVertices());
	uint pointID = SendPoint();

	mLevel.CreateBoxes(boxID, textureBoxID, shaderID);
	mLevel.CreateGround(groundID, textureGroundID, shaderID);


	mPacman = Pacman( 0.05, vec3(1, 0, 0), pointID, texturePacmanID, billboardShaderID, mLevel.GetPacmanSpawn(), 0.8 );
	for( int i = 0; i < mLevel.GetCandyPosList().size(); i++ )
		mCandyList.push_back(new Candy( pointID, textureCandyID, billboardShaderID, mLevel.GetCandyPosList()[i], 0.1 ));

	mLight = Light(mPacman.GetWorldPos(), 15.0, vec3(0.8, 0.8, 0), vec3(0.5, 0.5, 0), shaderID);
	mBridge.UpdateUniform("range", mLight.GetShaderID(), mLight.GetRange());
	mBridge.UpdateUniform("Light.Ld", mLight.GetShaderID(), mLight.GetDiffuse());
	mBridge.UpdateUniform("Light.Ls", mLight.GetShaderID(), mLight.GetSpecular());
}

void GameCore::Update(){
	/*
	hax... vi f�r fixa en b�ttre l�sning sen
	*/
	int i[4];
	int *j = mLevel.GetSurroundingGrid(mPacman.GetGridPosition());
	i[0] = j[0];
	i[1] = j[1];
	i[2] = j[2];
	i[3] = j[3];

	mBridge.TempCamUpdate();
	mPacman.Update(i);
	for (int i = 0; i < mGhostList.size(); i++)
		mGhostList[i]->Update();
	for (int i = 0; i < mEffects.size(); i++)
	{
		if(mEffects[i]->GetTimeLeft() <= 0)
		{
			delete mEffects[i];

			mEffects.erase(mEffects.begin()+i);
		}
		else
			mPoints += mEffects[i]->Run();
	}

}

void GameCore::CheckCollision(){
	PacmanCollisionCandy();
	GhostCollisionPacman();
}

void GameCore::PacmanCollisionCandy(){
	for (int i = 0; i < mCandyList.size(); i++)
	{
		if (mPacman.Collision(mCandyList[i], 0.2))
		{
			mEffects.push_back(((Candy*)mCandyList[i])->GetEffect());

			//Candy* tCandy = (Candy*)mCandyList[i];

			delete (Candy*)mCandyList[i];

			mCandyList.erase(mCandyList.begin()+i); // remove candy

			//delete tCandy;
			break;
		}
	}
}

void GameCore::GhostCollisionPacman(){
	for(int i = 0; i < mGhostList.size(); i++)
	{
		if (mGhostList[i]->Collision(&mPacman, 1))
		{
			mEffects.push_back(mGhostList[i]->GetEffect());
			break;
		}
	}
}

void GameCore::RenderObjects(){
	mBridge.BeginRendering(); // ADDED!

	mBridge.UpdateUniform("LightWorldPos", mLight.GetShaderID(), mPacman.GetWorldPos());

	//Render Ground
	mBridge.RenderObject(mLevel.GetGround());
	//Render Boxes
	mBridge.RenderObject(mLevel.GetBoxes());
	
	// Render Pacman
	mBridge.RenderObject(mPacman);
	// Render Candy
	mBridge.RenderObjects(mCandyList);
	/*for (int i = 0; i < mCandyList.size(); i++)
		mBridge.RenderObject(mCandyList[i]);
	// Render Ghost
	for (int i = 0; i < mGhostList.size(); i++)
		mBridge.RenderObject(mGhostList[i]);*/

	mBridge.EndRendering(); // ADDED!
}

uint GameCore::SendPoint()
{
	return mBridge.SendModel(vec3(0,0,0));
}

GameCore::~GameCore()
{
	for(int i = 0; i < mCandyList.size(); i++)
		delete mCandyList[i];
}