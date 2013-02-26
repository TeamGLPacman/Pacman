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

	mLevel.LoadMap("../Maps/map001.png");

	uint boxID = SendBoxVertices();
	uint groundID = SendGroundVertices();
	uint pointID = SendPoint();

	mLevel.BuildBoxes(boxID, textureBoxID, shaderID);
	mLevel.BuildGround(groundID, textureGroundID, shaderID);


	mPacman = Pacman( 0.01, vec3(1, 0, 0), pointID, texturePacmanID, billboardShaderID, mLevel.GetPacmanSpawn(), 0.8 );
}

void GameCore::Update(){
	mBridge.TempCamUpdate();
	
	mPacman.Update(mLevel.GetSurroundingGrid(mPacman.GetGridPosition()));
	for (int i = 0; i < mGhostList.size(); i++)
		mGhostList[i].Update();
	for (int i = 0; i < mEffects.size(); i++)
		mEffects[i]->Run();
}

void GameCore::CheckCollision(){
	PacmanCollisionCandy();
	GhostCollisionPacman();
}

void GameCore::PacmanCollisionCandy(){
	for (int i = 0; i < mCandyList.size(); i++)
	{
		if (mPacman.Collision(mCandyList[i], 1))
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
		if (mGhostList[i].Collision(mPacman, 1))
		{
			mEffects.push_back(mGhostList[i].GetEffect());
			break;
		}
	}
}

void GameCore::RenderObjects(){
	mBridge.BeginRendering(); // ADDED!

	//Render Ground
	mBridge.RenderObject(mLevel.GetGround());
	//Render Boxes
	mBridge.RenderObjects(mLevel.GetBoxList());
	
	// Render Pacman
	mBridge.RenderObject(mPacman);
	// Render Candy
	/*for (int i = 0; i < mCandyList.size(); i++)
		mBridge.RenderObject(mCandyList[i]);
	// Render Ghost
	for (int i = 0; i < mGhostList.size(); i++)
		mBridge.RenderObject(mGhostList[i]);*/

	mBridge.EndRendering(); // ADDED!
}

uint GameCore::SendBoxVertices()
{
	vector<VertexPoint> verts;

	/*
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,-1,0), vec2(0.666467,0.666467)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(0,-1,0), vec2(0.333533,0.666467)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(0,-1,0), vec2(0.333533,0.333533)));

	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,-1,0), vec2(0.666467,0.333533)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,-1,0), vec2(0.666467,0.666467)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(0,-1,0), vec2(0.333533,0.333533)));
	*/

	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(-0,1,0), vec2(0.333333,0.333333)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,-0.5), vec3(-0,1,0), vec2(0.0000,0.333333)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0,1,0), vec2(0.0000,0.0000)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(-0,1,0), vec2(0.333333,0.0000)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(-0,1,0), vec2(0.333333,0.333333)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0,1,0), vec2(0.0000,0.0000)));

	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(1,-0,1e-006), vec2(0.666666,0.0000)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(1,-0,1e-006), vec2(0.666666,0.333333)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(1,-0,1e-006), vec2(0.333333,0.333333)));

	verts.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(1,0,-0), vec2(0.333333,0.0000)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(1,0,-0), vec2(0.666666,0.0000)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(1,0,-0), vec2(0.333333,0.333333)));

	verts.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(-0,-0,1), vec2(1.00000,0.333533)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(-0,-0,1), vec2(1.00000,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(-0,-0,1), vec2(0.666666,0.333333)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(-0,-0,1), vec2(1.00000,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0,-0,1), vec2(0.666666,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(-0,-0,1), vec2(0.666666,0.333333)));

	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(-1,-0,-0), vec2(0.0000,1.00000)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-1,-0,-0), vec2(0.0000,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(-1,-0,-0), vec2(0.333333,1.00000)));

	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-1,-0,-0), vec2(0.0000,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,-0.5), vec3(-1,-0,-0), vec2(0.333333,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(-1,-0,-0), vec2(0.333333,1.0)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(0,0,-1), vec2(0.333333,0.333333)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,0,-1), vec2(0.333333,0.666666)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,0,-1), vec2(0.0000,0.666666)));

	verts.push_back(VertexPoint(vec3(-0.5,0.5,-0.5), vec3(0,0,-1), vec2(0.0000,0.333333)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(0,0,-1), vec2(0.333333,0.333333)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,0,-1), vec2(0.0000,0.666666)));


	return mBridge.SendModel(verts);
}

uint GameCore::SendPoint()
{
	return mBridge.SendModel(vec3(0,0,0));
}

uint GameCore::SendGroundVertices()
{
	vector<VertexPoint> verts;

	int width = mLevel.GetWidth();
	int height = mLevel.GetHeight();

	verts.push_back(VertexPoint(vec3(-0.5,0,-0.5), vec3(0,1,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(-0.5,0,height - 0.5), vec3(0,1,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(width - 0.5,0,height - 0.5), vec3(0,1,0), vec2(0,1)));

	verts.push_back(VertexPoint(vec3(-0.5,0,-0.5), vec3(0,1,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(width - 0.5,0,height - 0.5), vec3(0,1,0), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(width - 0.5,0,-0.5), vec3(0,1,0), vec2(1,1)));

	return mBridge.SendModel(verts);
}