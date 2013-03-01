#ifndef SOUNDSOURCE_H_
#define SOUNDSOURCE_H_
#include "CommonIncludes.h"
#include <cstdlib>
#include "al.h"
#include "alc.h"

class SoundSource
{
private:
	vec3 *mPosition;
	float mVolume;
	float mPitch;
	bool mLoop;

	ALuint mSource;              //Is the name of source (where the sound come from)
    ALuint mBuffer;              //Stores the sound data
	unsigned char* soundData;

	int endWithError(char* msg, int error=0)
	{
		//Display error message in console
		cout << msg << "\n";
		system("PAUSE");
		return error;
	}

public:
	SoundSource(const char* file, vec3 *pos, float volume, float pitch, bool loop);
	SoundSource();
	~SoundSource();

	int LoadFile(const char* file);
	void SetPosition(vec3 *pos);
	void SetVolume(float vol);

	uint GetSource();
	uint GetBuffer();
	vec3 GetPosition();
	float GetVolume();
	float GetPitch();
	bool GetIfLoop();

	void DeleteData();
};
#endif
