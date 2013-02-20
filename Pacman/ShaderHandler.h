#ifndef SHADERHANDLER_H_
#define SHADERHANDLER_H_
#include "CommonIncludes.h"
#include <fstream>

class ShaderHandler
{
public:
	ShaderHandler(void);
	~ShaderHandler(void);

	GLuint CompileShaderFile(const char* shaderFile, const int& type); 
	GLuint CreateShaderProgram(const char* shaderAFile, const char* shaderBFile); 
	GLuint CreateShaderProgram(const char* shaderAFile, const char* shaderBFile, const char* shaderCFile);
	int UpdateUniform(const char* variable, GLuint shaderProgHandle, const void* value); 
};

#endif