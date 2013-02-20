#ifndef SHADERHANDLER_H_
#define SHADERHANDLER_H_
#include "CommonIncludes.h"
#include <fstream>

class ShaderHandler
{
public:
	ShaderHandler(void);
	~ShaderHandler(void);

	bool CompileShaderFile(const char* shaderFile, const int& type, GLuint& shaderHandle); 
	bool CreateShaderProgram(const GLuint& shaderAHandle, const GLuint& shaderBHandle, GLuint& shaderProgHandle); 
	bool CreateShaderProgram(const GLuint& shaderAHandle, const GLuint& shaderBHandle, const GLuint& shaderCHandle, GLuint& shaderProgHandle);
	int UpdateUniform(const char* variable, GLuint shaderProgHandle, const void* value); 
};

#endif