#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_
#include "SOIL.h"
#include <fstream>
#include "CommonIncludes.h"

class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);

	uint LoadTexture(const char* file);
};
#endif
