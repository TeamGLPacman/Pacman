#include "SoundHandler.h"


SoundHandler::SoundHandler()
{
}

SoundHandler::~SoundHandler()
{
	alcDestroyContext(context);                                                 //Destroy the OpenAL Context
    alcCloseDevice(device);                                                     //Close the OpenAL Device

}

int SoundHandler::Init()
{
	 //Now OpenAL needs to be initialized 
    const ALCchar *default_device;

	default_device = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);

    device = alcOpenDevice(default_device);                                               //Open the device

    if(device == NULL) return endWithError("no sound device");                         //Error during device oening
    context = alcCreateContext(device, NULL);                                   //Give the device a context
    alcMakeContextCurrent(context);                                             //Make the context the current
    if(!context) return endWithError("no sound context");                       //Error during context handeling
 
}

void SoundHandler::UpdateSounds(vector<SoundSource> sounds, vec3 pacmanPos, vec3 pacmanDir, float pacSpeed)
{
	//Sound setting variables
    ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };                                    //Velocity of the source sound
    ALfloat ListenerPos[] = { pacmanPos.x, pacmanPos.y, pacmanPos.z };                                  //Position of the listener
    ALfloat ListenerVel[] = { pacmanDir.x*pacSpeed, pacmanDir.y*pacSpeed, pacmanDir.z*pacSpeed };                                  //Velocity of the listener
    ALfloat ListenerOri[] = { pacmanDir.x, pacmanDir.y, pacmanDir.z,  0.0, 1.0, 0.0 };                 //Orientation of the listener
                                                                                //First direction vector, then vector pointing up) 
    //Listener                                                                               
    alListenerfv(AL_POSITION,    ListenerPos);                                  //Set position of the listener
    alListenerfv(AL_VELOCITY,    ListenerVel);                                  //Set velocity of the listener
    alListenerfv(AL_ORIENTATION, ListenerOri);                                  //Set orientation of the listener
    
	for(int i = 0; i < sounds.size(); i++)
	{
		ALfloat SourcePos[] = { sounds[i].GetPosition().x, sounds[i].GetPosition().y, sounds[i].GetPosition().z };        //Position of the source sound
		//Source
		alSourcei (sounds[i].GetSource(), AL_BUFFER,   sounds[i].GetBuffer() );                                 //Link the buffer to the source
		alSourcef (sounds[i].GetSource(), AL_PITCH,    sounds[i].GetPitch() );                                 //Set the pitch of the source
		alSourcef (sounds[i].GetSource(), AL_GAIN,     sounds[i].GetVolume() );                                 //Set the gain of the source
		alSourcefv(sounds[i].GetSource(), AL_POSITION, SourcePos);                                 //Set the position of the source
		alSourcefv(sounds[i].GetSource(), AL_VELOCITY, SourceVel);                                 //Set the velocity of the source
		alSourcei (sounds[i].GetSource(), AL_LOOPING,  sounds[i].GetIfLoop() );                                 //Set if source is looping sound
	}
}

void SoundHandler::PlaySound(uint source)
{
	//PLAY 
    alSourcePlay(source);                                                       //Play the sound buffer linked to the source
    //if(alGetError() != AL_NO_ERROR) return endWithError("Error playing sound"); //Error when playing sound
}

void SoundHandler::PauseSound(uint source)
{
	alSourcePause(source); 
}

void SoundHandler::StopSound(uint source)
{
	alSourceStop(source); 
}
