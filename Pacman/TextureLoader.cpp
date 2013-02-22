#include "TextureLoader.h"


TextureLoader::TextureLoader(void)
{
}

TextureLoader::~TextureLoader(void)
{
}

uint TextureLoader::LoadTexture(const char* file, uint shaderProgHandle) 
{
	int width, height, channels;
		// Load texture file data
	unsigned char* imgData = SOIL_load_image(file, &width, &height, &channels, 4 );

	uint textureHandle;
	// Copy file to OpenGL
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	gluBuild2DMipmaps(GL_TEXTURE_2D, channels, width, height, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

	// Set the Tex1 sampler uniform to refer to texture unit 0
	GLuint loc = glGetUniformLocation(shaderProgHandle, "Tex1");
	if( loc >= 0 )
		glUniform1i(loc, 0);
	else
		fprintf(stderr, "Uniform variable Tex1 not found!\n");
		
	return textureHandle;
}