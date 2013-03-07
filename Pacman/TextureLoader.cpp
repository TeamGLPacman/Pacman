#include "TextureLoader.h"


TextureLoader::TextureLoader(void)
{
}

TextureLoader::~TextureLoader(void)
{
}

uint TextureLoader::LoadTexture(const char* file) 
{
	int width, height, channels;
		// Load texture file data
	unsigned char* imgData = SOIL_load_image(file, &width, &height, &channels, 4 );

	uint textureHandle;
	// Copy file to OpenGL
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	gluBuild2DMipmaps(GL_TEXTURE_2D, channels, width, height, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
	
	delete imgData;
	return textureHandle;
}