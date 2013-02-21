#include "TextureLoader.h"


TextureLoader::TextureLoader(void)
{
}

TextureLoader::~TextureLoader(void)
{
}

uint TextureLoader::LoadTexture_TGA(const char* file, UINT shaderProgHandle) {
	
	const size_t size_uchar = sizeof(uchar);
	const size_t size_sint = sizeof(sint);

	tga_data_t* tga = NULL;
	FILE* fh = NULL;
	int md, t;
	// Allocate memory for the info structure. 
	tga = (tga_data_t*)malloc(sizeof(tga_data_t));
	fh = fopen(file, "rb"); // Open the file in binary mode. 
	if (fh == NULL) { // Problem opening file? 
		fprintf(stderr, "Error: problem opening TGA file (%s).\n", file);
	} else {
		tga = (tga_data_t*)malloc(sizeof(tga_data_t));
		{ // Load information about the tga, aka the header.
			fseek(fh, 12, SEEK_SET); // Seek to the width.
			fread(&tga->w, size_sint, 1, fh);
			fseek(fh, 14, SEEK_SET); // Seek to the height.
			fread(&tga->h, size_sint, 1, fh);
			fseek(fh, 16, SEEK_SET); // Seek to the depth.
			fread(&tga->depth, size_sint, 1, fh);
		}
		{ // Load the actual image data.
			md = tga->depth / 8; // Mode = components per pixel.
			t = tga->h * tga->w * md; // Total bytes = h * w * md.
			printf("Reading %d bytes.\n", t);
			tga->data = (uchar*)malloc(size_uchar * t); // Allocate memory for the image data.
			fseek(fh, 18, SEEK_SET); // Seek to the image data.
			fread(tga->data, size_uchar, t, fh);
			fclose(fh); // We're done reading.
			if (md >= 3) { // Mode 3 = RGB, Mode 4 = RGBA
				uchar aux;  // TGA stores RGB(A) as BGR(A) so
				for (int i = 0; i < t; i+= md) {
					aux = tga->data[i]; // we need to swap red and blue.
					tga->data[i] = tga->data[i + 2];
					tga->data[i + 2] = aux;
				}
			}
		}
		printf("Loaded texture -> (%s)\nWidth: %d\nHeight: %d\nDepth: %d\n", file, tga->w, tga->h, tga->depth);
	}

	// Copy file to OpenGL
	glActiveTexture(GL_TEXTURE0);
	GLuint textureHandle;
	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, tga->w, tga->h, GL_RGB, GL_UNSIGNED_BYTE, tga->data);
	
	// Set the Tex1 sampler uniform to refer to texture unit 0
	GLuint loc = glGetUniformLocation(shaderProgHandle, "Tex1");
	if( loc >= 0 )
		glUniform1i(loc, 0);
	else
		fprintf(stderr, "Uniform variable Tex1 not found!\n");
		
	return textureHandle;
}