#ifndef SOUNDHANDLER_H_
#define SOUNDHANDLER_H_
#include "CommonIncludes.h"
#include <cstdlib>
#include "al.h"
#include "alc.h"
#include "SoundSource.h"

class SoundHandler
{
private:
	ALCdevice *device;         //Create an OpenAL Device
    ALCcontext *context;        //And an OpenAL Context
	
	ALuint *sources;
	ALuint *buffers;

	int endWithError(char* msg, int error=0)
	{
		//Display error message in console
		cout << msg << "\n";
		system("PAUSE");
		return error;
	}
public:
	SoundHandler();
	~SoundHandler();

	int Init();
	int PlaySound(uint sourceHandle);
	void UpdateSounds(vector<SoundSource> sounds, vec3 pacmanPos, vec3 pacmanDir, float pacSpeed);
	void ClearSoundData();
};
#endif

