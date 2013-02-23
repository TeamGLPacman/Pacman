#include "GameCore.h"

GameCore::GameCore()
{
}

int GameCore::GameLoop(){
	while(true){
		Update(); // Update Entities
		CheckCollision(); // Checking Collisions
		RenderObjects(); // Draw Objects
		// if press esc exit(1);
	}
	return 0;
}

void GameCore::Initialize( int argc, char** argv ){
	uint test = mBridge.Initialize( argc, argv );


	// SKAPA CANDY, GHOST, PACMAN OCH LEVEL
	
	
	uint shaderID = mBridge.LoadShaderFiles("../Shaders/shader.vertex", "../Shaders/shader.fragment");

	uint textureBoxID = mBridge.LoadTexture("../Textures/Wall.png");
	uint textureGroundID = mBridge.LoadTexture("../Textures/Floor.png");



	mLevel.LoadMap("../Maps/map001.png");

	uint boxID = SendBoxVertices();
	uint groundID = SendGroundVertices();
	uint pointID = SendPoint();

	mLevel.BuildBoxes(boxID, textureBoxID, shaderID);
	mLevel.BuildGround(groundID, textureGroundID, shaderID);
}

void GameCore::Update(){
	mPacman.Update();
	mPacman.Update();
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
	for (int i = 0; i < mLevel.GetBoxList().size(); i++)
		mBridge.RenderObject(mLevel.GetBoxList()[i]);
	/*
	// Render Pacman
	mBridge.RenderObject(mPacman);
	// Render Candy
	for (int i = 0; i < mCandyList.size(); i++)
		mBridge.RenderObject(mCandyList[i]);
	// Render Ghost
	for (int i = 0; i < mGhostList.size(); i++)
		mBridge.RenderObject(mGhostList[i]);*/

	mBridge.EndRendering(); // ADDED!
}

uint GameCore::SendBoxVertices()
{
	vector<VertexPoint> verts;

	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,-0.5,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(0,-0.5,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(0,-0.5,0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(-0,0.5,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,-0.5), vec3(-0,0.5,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0,0.5,0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0.5,0,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(0.5,0,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(0.5,0,0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(-0,0,0.5), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(-0,0,0.5), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(-0,0,0.5), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(-0.5,0,-0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0.5,0,-0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(-0.5,0,-0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(0,0,-0.5), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,0,-0.5), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,0,-0.5), vec2(1,1)));



	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,-0.5,0), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0,-0.5,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(0,-0.5,0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(-0,0.5,0), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(-0,0.5,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0,0.5,0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,-0.5,0.5), vec3(0.5,0,-0), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(0.5,-0.5,-0.5), vec3(0.5,0,-0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(0.5,0,-0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(0.5,0.5,0.5), vec3(-0,0,0.5), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0,0,0.5), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,0.5), vec3(-0,0,0.5), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(-0.5,0.5,0.5), vec3(-0.5,0,-0), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(-0.5,0.5,-0.5), vec3(-0.5,0,-0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(-0.5,0,-0), vec2(1,1)));

	verts.push_back(VertexPoint(vec3(-0.5,0.5,-0.5), vec3(0,0,-0.5), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(0.5,0.5,-0.5), vec3(0,0,-0.5), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(-0.5,-0.5,-0.5), vec3(0,0,-0.5), vec2(1,1)));

	return mBridge.SendModel(verts);
}

uint GameCore::SendPoint()
{
	return 1;
}

uint GameCore::SendGroundVertices()
{
	vector<VertexPoint> verts;

	int width = mLevel.GetWidth();
	int height = mLevel.GetHeight();

	verts.push_back(VertexPoint(vec3(0,0,0), vec3(0,-1,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(0,0,height), vec3(0,-1,0), vec2(0,0)));
	verts.push_back(VertexPoint(vec3(width,0,height), vec3(0,-1,0), vec2(0,1)));

	verts.push_back(VertexPoint(vec3(0,0,0), vec3(0,-1,0), vec2(1,0)));
	verts.push_back(VertexPoint(vec3(width,0,height), vec3(0,-1,0), vec2(0,1)));
	verts.push_back(VertexPoint(vec3(width,0,0), vec3(0,-1,0), vec2(1,1)));

	return mBridge.SendModel(verts);
}