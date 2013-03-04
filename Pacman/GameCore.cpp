#include "GameCore.h"


GameCore::GameCore()
{
	mSoundsStarted = false;
}

void wait ( float seconds )
{
 clock_t endwait;
 endwait = clock () + seconds * CLOCKS_PER_SEC ;
 while (clock() < endwait) {}
}

int GameCore::GameLoop(){
	//GameLoop
	while(StillRunning()){
		Update(); // Update Entities
		CheckCollision(); // Checking Collisions
		RenderObjects(); // Draw Objects

		if(GetAsyncKeyState(VK_ESCAPE) != 0)
			return 0;
		wait(0.01f);
	}
	return 0;
}

bool GameCore::StillRunning()
{
	return mPacman.StillAlive() || mCandyList.size() == 0;
}

void GameCore::Initialize( int argc, char** argv ){
	uint test = mBridge.Initialize( argc, argv );
	mSoundHandler.Init();

	// Load/Create Shaders
	uint shaderID = mBridge.LoadShaderFiles("../Shaders/shader.vertex", "../Shaders/shader.fragment");
	uint billboardShaderID = mBridge.LoadShaderFiles("../Shaders/billboardShader.vertex", "../Shaders/billboardShader.fragment", "../Shaders/billboardShader.geometry" );

	// Load Textures
	uint textureBoxID = mBridge.LoadTexture("../Textures/Wall.png");
	uint textureGroundID = mBridge.LoadTexture("../Textures/Floor.png");
	uint texturePacmanID = mBridge.LoadTexture("../Textures/Pacman.png");
	uint textureCandyID = mBridge.LoadTexture("../Textures/Candy.png");
	uint textureGhostID = mBridge.LoadTexture("../Textures/Ghost-256.png");

	// Load Level
	mLevel.LoadMap("../Maps/map001.png");

	// Load Models
	uint wallID = mBridge.SendModel(mLevel.GetWallVertices());
	uint groundID = mBridge.SendModel(mLevel.GetGroundVertices());
	uint pointID = SendPoint();

	// Create Level
	mLevel.CreateWalls(wallID, textureBoxID, shaderID);
	mLevel.CreateGround(groundID, textureGroundID, shaderID);
	
	//Create Pacman
	mPacman = Pacman( 0.08, vec3(1, 0, 0), pointID, texturePacmanID, billboardShaderID, vec3(1,1,0), mLevel.GetPacmanSpawn(), 0.8 );

	//Create Candy
	for( int i = 0; i < mLevel.GetCandyPosList().size(); i++ )
		mCandyList.push_back(new Candy( pointID, textureCandyID, billboardShaderID, vec3(1, 1, 1), mLevel.GetCandyPosList()[i], 0.1, new Points(10)));

	for( int i = 0; i < mLevel.GetSpecCandyPosList().size(); i++ )
		mCandyList.push_back(new Candy( pointID, textureCandyID, billboardShaderID, vec3(1, 0.2, 0.2), mLevel.GetSpecCandyPosList()[i], 0.3, new PowerPacman(&mPacman, mGhostList) ));

	// Create Ghosts
	Behaviour *a;
	for(int i = 0; i < 5; i++)
	{
		vec3 colours[] = { vec3(1,0,0), vec3(0,1,0), vec3(1,0,1), vec3(0,1,1), vec3(0.8, 1, 0) };

		a = new Hunt(mPacman.GetPosition(), new KillPacman());
		mGhostList.push_back(new Ghost( 0.05, vec3(1, 0, 0), pointID, textureGhostID, billboardShaderID,colours[i], mLevel.GetGhostSpawn(), 0.8, a));
	}

	// Adding Light
	mLight = Light(mPacman.GetWorldPos(), 15.0, vec3(0.8, 0.8, 0), vec3(0.5, 0.5, 0), shaderID);
	mBridge.UpdateUniform("range", mLight.GetShaderID(), mLight.GetRange());
	mBridge.UpdateUniform("Light.Ld", mLight.GetShaderID(), mLight.GetDiffuse());
	mBridge.UpdateUniform("Light.Ls", mLight.GetShaderID(), mLight.GetSpecular());

	// Load Music/Sounds
	mMusicSound = SoundSource("../Audio/DaftPunk.wav", mPacman.GetPositionPointer(), 0.2, 1.0, true);
	mSoundList.push_back(mMusicSound);
	mPowerPacmanSound = SoundSource("../Audio/Ghostbusters.wav", mPacman.GetPositionPointer(), 0.8, 1.2, true);
	mSoundList.push_back(mPowerPacmanSound);
	mEatSound = SoundSource("../Audio/pop.wav", mPacman.GetPositionPointer(), 0.7, 1.0, false);
	mSoundList.push_back(mEatSound);
	mDeathSound = SoundSource("../Audio/pacman_death.wav", mPacman.GetPositionPointer(), 0.9, 1.0, false);
	mSoundList.push_back(mDeathSound);

	for(int i = 0; i < mGhostList.size(); i++)
	{
		mGhostSounds.push_back(SoundSource("../Audio/haunting.wav", mGhostList[i]->GetPositionPointer(), 0.4, 1.4, true));
		mSoundList.push_back(mGhostSounds[i]);
	}
	mBridge.UpdateCamera(mPacman.GetWorldPos()-mPacman.GetDirection()-mPacman.GetDirection()+vec3(0,1,0), vec3(mPacman.GetWorldPos() + mPacman.GetDirection()) );
}

void GameCore::Update(){
	UpdateCamera();
	UpdatePacman();
	UpdateGhost();
	UpdateEffects();
	UpdateSounds();
}

void GameCore::UpdateGhost()
{
	for (int i = 0; i < mGhostList.size(); i++)
	{
		int v[4];
		int *j = mLevel.GetSurroundingGrid(mGhostList[i]->GetGridPosition());
		v[0] = j[0];
		v[1] = j[1];
		v[2] = j[2];
		v[3] = j[3];
		mGhostList[i]->Update(v);
	}
}
void GameCore::UpdatePacman()
{
	int i[4];
	int *j = mLevel.GetSurroundingGrid(mPacman.GetGridPosition());
	i[0] = j[0];
	i[1] = j[1];
	i[2] = j[2];
	i[3] = j[3];
	mPacman.Update(i);
}
void GameCore::UpdateEffects()
{
	for (int i = 0; i < mEffects.size(); i++)
	{
		if(mEffects[i]->GetTimeLeft() < 0)
		{
			Effect *toRemove = mEffects[i];
			mEffects.erase(mEffects.begin()+i);
			toRemove->Reset();
			i--;
		}
		else
			mPoints += mEffects[i]->Run();
	}
}
void GameCore::UpdateSounds()
{
	mSoundHandler.UpdateSounds(mSoundList, mPacman.GetWorldPos(), mPacman.GetDirection(), mPacman.GetSpeed());

	if(!mSoundsStarted)
	{
		mSoundHandler.PlaySound(mMusicSound.GetSource());
		for(int i = 0; i < mGhostSounds.size(); i++)
		{
			mSoundHandler.PlaySound(mGhostSounds[i].GetSource());
		}
		mSoundsStarted = true;
	}

	for(int i = 0; i < mGhostSounds.size(); i++)
	{
		mGhostSounds[i].SetPosition(mGhostList[i]->GetPositionPointer());
	}
	mEatSound.SetPosition(mPacman.GetPositionPointer());
	mPowerPacmanSound.SetPosition(mPacman.GetPositionPointer());
}
void GameCore::UpdateCamera()
{
	if(GetAsyncKeyState(VK_SPACE) == 0)
		mBridge.UpdateCameraSmooth(mPacman.GetWorldPos()-mPacman.GetDirection()-mPacman.GetDirection()-mPacman.GetDirection()+vec3(0,2,0), vec3(mPacman.GetWorldPos() + mPacman.GetDirection()), mPacman.GetSpeed());
	else
		//mBridge.UpdateCameraSmooth(vec3(15.0,36.0,15.0), vec3(15.0,35.0,15.0), 0.4f);
	    mBridge.UpdateCameraSmooth(vec3(15.0,36.0,15.0), vec3(mPacman.GetWorldPos()), 0.4f);
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
			mSoundHandler.PlaySound(mEatSound.GetSource());
			if(mCandyList[i]->GetSize() >= 0.3)
			{
				mSoundHandler.StopSound(mMusicSound.GetSource());
				for(int i = 0; i < mGhostList.size(); i++)
					mSoundHandler.StopSound(mGhostSounds[i].GetSource());

				mSoundHandler.PlaySound(mPowerPacmanSound.GetSource());
			}
			mEffects.push_back(((Candy*)mCandyList[i])->GetEffect());
			
			delete (Candy*)mCandyList[i];

			mCandyList.erase(mCandyList.begin()+i); // remove candy
			break;
		}
	}
}
void GameCore::GhostCollisionPacman(){
	for(int i = 0; i < mGhostList.size(); i++)
	{
		if (mGhostList[i]->Collision(&mPacman, 0.5))
		{
			mDeathSound.SetPosition(mPacman.GetPositionPointer());
			mSoundHandler.PlaySound(mDeathSound.GetSource());
			wait(1.8);
			mEffects.push_back(mGhostList[i]->GetEffect());
			mEffects[mEffects.size()-1]->AddPacman(&mPacman);
			for(int i = 0; i < mGhostList.size(); i++)
				mEffects[mEffects.size()-1]->AddEntity((Entity*)mGhostList[i]);
			break;
		}
	}
}

void GameCore::RenderObjects(){
	mBridge.BeginRendering();

	mBridge.UpdateUniform("LightWorldPos", mLight.GetShaderID(), mPacman.GetWorldPos());
	//Render Ground
	mBridge.RenderObject(&(mLevel.GetGround()));

	//Render Walls
	mBridge.RenderObject(&(mLevel.GetWalls()));
	
	// Render Candy (enbart test av optimering)
	for(int i = 0; i < mCandyList.size(); i++)
	{
		mBridge.UpdateUniform("billboardColor" , mCandyList[i]->GetShaderID(), mCandyList[i]->GetColor());
		mBridge.RenderObject(mCandyList[i]);
	}
	
	// Render Ghost
	for (int i = 0; i < mGhostList.size(); i++)
	{
		mBridge.UpdateUniform("billboardColor" , mGhostList[i]->GetShaderID(), mGhostList[i]->GetColor());
		mBridge.RenderObject(mGhostList[i]);
	}
	
	// Render Pacman
	mBridge.UpdateUniform("billboardColor" , mPacman.GetShaderID(), mPacman.GetColor());
	mBridge.RenderObject(&mPacman);
	
	mBridge.EndRendering();
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