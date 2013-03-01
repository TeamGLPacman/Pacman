#include "SoundSource.h"


SoundSource::SoundSource(const char* file, vec3 *pos, float volume, float pitch, bool loop)
{
	LoadFile(file);
	mPosition = pos;
	mVolume = volume;
	mPitch = pitch;
	mLoop = loop;
}

SoundSource::SoundSource()
{
}

SoundSource::~SoundSource()
{
}

int SoundSource::LoadFile(const char* file)
{
	//Variables to store info about the WAVE file (all of them is not needed for OpenAL)
    char type[4];
    DWORD size,chunkSize;
    short formatType,channels;
    DWORD sampleRate,avgBytesPerSec;
    short bytesPerSample,bitsPerSample;
    DWORD dataSize;

	//Loading of the WAVE file
    FILE *fp = NULL;                                                            //Create FILE pointer for the WAVE file
    fp=fopen(file,"rb");                                            //Open the WAVE file
    if (!fp) return endWithError("Failed to open file");                        //Could not open file
    
    //Check that the WAVE file is OK
    fread(type,sizeof(char),4,fp);                                              //Reads the first bytes in the file
    if(type[0]!='R' || type[1]!='I' || type[2]!='F' || type[3]!='F')            //Should be "RIFF"
    return endWithError ("No RIFF");                                            //Not RIFF

    fread(&size, sizeof(DWORD),1,fp);                                           //Continue to read the file
    fread(type, sizeof(char),4,fp);                                             //Continue to read the file
    if (type[0]!='W' || type[1]!='A' || type[2]!='V' || type[3]!='E')           //This part should be "WAVE"
    return endWithError("not WAVE");                                            //Not WAVE
    
    fread(type,sizeof(char),4,fp);                                              //Continue to read the file
    if (type[0]!='f' || type[1]!='m' || type[2]!='t' || type[3]!=' ')           //This part should be "fmt "
    return endWithError("not fmt ");                                            //Not fmt 
    
    //Now we know that the file is a acceptable WAVE file
    //Info about the WAVE data is now read and stored
    fread(&chunkSize,sizeof(DWORD),1,fp);
    fread(&formatType,sizeof(short),1,fp);
    fread(&channels,sizeof(short),1,fp);
    fread(&sampleRate,sizeof(DWORD),1,fp);
    fread(&avgBytesPerSec,sizeof(DWORD),1,fp);
    fread(&bytesPerSample,sizeof(short),1,fp);
    fread(&bitsPerSample,sizeof(short),1,fp);
    
    fread(type,sizeof(char),4,fp);
    if (type[0]!='d' || type[1]!='a' || type[2]!='t' || type[3]!='a')           //This part should be "data"
    return endWithError("Missing DATA");                                        //not data
    
    fread(&dataSize,sizeof(DWORD),1,fp);                                        //The size of the sound data is read
    
    //Display the info about the WAVE file
    cout << "Chunk Size: " << chunkSize << "\n";
    cout << "Format Type: " << formatType << "\n";
    cout << "Channels: " << channels << "\n";
    cout << "Sample Rate: " << sampleRate << "\n";
    cout << "Average Bytes Per Second: " << avgBytesPerSec << "\n";
    cout << "Bytes Per Sample: " << bytesPerSample << "\n";
    cout << "Bits Per Sample: " << bitsPerSample << "\n";
    cout << "Data Size: " << dataSize << "\n";
        
    soundData = new unsigned char[dataSize];                            //Allocate memory for the sound data. kalla denna soundData
    cout << fread(soundData,sizeof(BYTE),dataSize,fp) << " bytes loaded\n";           //Read the sound data and display the 
                                                                                //number of bytes loaded.
                                                                                //Should be the same as the Data Size if OK

	ALuint frequency = sampleRate;                                               //The Sample Rate of the WAVE file
	ALenum format=0;                                                            //The audio format (bits per sample, number of channels)
    
	//Figure out the format of the WAVE file
	if(bitsPerSample == 8)
	{
		if(channels == 1)
			format = AL_FORMAT_MONO8;
		else if(channels == 2)
			format = AL_FORMAT_STEREO8;
	}
	else if(bitsPerSample == 16)
	{
		if(channels == 1)
			format = AL_FORMAT_MONO16;
		else if(channels == 2)
			format = AL_FORMAT_STEREO16;
	}
	if(!format) return endWithError("Wrong BitPerSample");                      //Not valid format

	alGenBuffers(1, &mBuffer);                                                    //Generate one OpenAL Buffer and link to "buffer"
    alGenSources(1, &mSource);                                                   //Generate one OpenAL Source and link to "source"
	if(alGetError() != AL_NO_ERROR) return endWithError("Error GenSource");     //Error during buffer/source generation

	alBufferData(mBuffer, format, soundData, dataSize, frequency);                    //Store the sound data in the OpenAL Buffer
	if(alGetError() != AL_NO_ERROR) 
	return endWithError("Error loading ALBuffer");                              //Error during buffer loading

	fclose(fp);
}

void SoundSource::SetPosition(vec3 *pos)
{
	mPosition = pos;
}

void SoundSource::SetVolume(float vol)
{
	mVolume = vol;
}

uint SoundSource::GetSource()
{
	return mSource;
}

uint SoundSource::GetBuffer()
{
	return mBuffer;
}

vec3 SoundSource::GetPosition()
{
	return *mPosition;
}

float SoundSource::GetVolume()
{
	return mVolume;
}

float SoundSource::GetPitch()
{
	return mPitch;
}

bool SoundSource::GetIfLoop()
{
	return mLoop;
}

void SoundSource::DeleteData()
{
	//Clean-up
    delete[] soundData;                                                               //Delete the sound data buffer
    alDeleteSources(1, &mSource);                                                //Delete the OpenAL Source
    alDeleteBuffers(1, &mBuffer);                                                 //Delete the OpenAL Buffer
    alcMakeContextCurrent(NULL);                                                //Make no context current
}