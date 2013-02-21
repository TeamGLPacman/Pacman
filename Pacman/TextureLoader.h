#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_
#include "TGALoader.h"
#include <fstream>
#include "CommonIncludes.h"

class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);

	uint LoadTexture_TGA(const char* file, UINT shaderProgHandle);
};
#endif
