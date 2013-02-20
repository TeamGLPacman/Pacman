#include "ShaderHandler.h"


ShaderHandler::ShaderHandler(void)
{
}


ShaderHandler::~ShaderHandler(void)
{
}

bool ShaderHandler::CompileShaderFile(const char* shaderFile, const int& type, GLuint& shaderHandle)
{
	// load file into string
	ifstream file;
	file.open(shaderFile);
	if (!file.is_open()) {
		printf("ERROR creating opening shader file %s\n", shaderFile);
		return false;
	}
	string shaderString; // string to load shader into
	char line[256];
  while (!file.eof()) {
    strcpy(line, "");
    file.getline(line, 256);
    shaderString += line;
    shaderString += '\n';
  }
  file.close();

	// create shader object
	if (type == 0) {
		shaderHandle = glCreateShader(GL_VERTEX_SHADER);
	} else if (type == 1) {
		shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	} else if (type == 2) {
		shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
	}
	// validate creation
	if (0 == shaderHandle) {
		printf("ERROR creating shader type %i\n", type);
		return false;
	}

	// load source from a char array
	const char* ptr = shaderString.c_str(); // get character pointer from string
	glShaderSource(shaderHandle, 1, &ptr, NULL);

	// compile shader
	glCompileShader(shaderHandle);

	// Check for errors
	int result = 0;
	glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &result);
	if(GL_FALSE == result) {
		printf("ERROR compiling shader type %i\n", type);
		int length = 0;
		glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &length);
		if(length > 0) {
			// create a log of error messages
			char* errorLog = new char[length];
			int written = 0;
			glGetShaderInfoLog(shaderHandle, length, &written, errorLog);
			printf("Shader error log;\n%s\n", errorLog);
			delete [] errorLog;
		}
		return false;
	}
	return true;
}

bool ShaderHandler::CreateShaderProgram(const GLuint& shaderAHandle, const GLuint& shaderBHandle, GLuint& shaderProgHandle)
{
	// create shader programme
	shaderProgHandle = glCreateProgram();
	if (0 == shaderProgHandle) {
		printf("ERROR creating shader programme\n");
		return false;
	}
	
	// attach shaders
	glAttachShader(shaderProgHandle, shaderAHandle);
	glAttachShader(shaderProgHandle, shaderBHandle);
	
	// link programme
	glLinkProgram(shaderProgHandle);
	
	// verify link status
	GLint status;
	glGetProgramiv(shaderProgHandle, GL_LINK_STATUS, &status);
	if (GL_FALSE == status) {
		printf("ERROR: failed to link shader programme\n");
		return false;
	}
	
	return true;
}

bool ShaderHandler::CreateShaderProgram(const GLuint& shaderAHandle, const GLuint& shaderBHandle, const GLuint& shaderCHandle, GLuint& shaderProgHandle)
{
	// create shader programme
	shaderProgHandle = glCreateProgram();
	if (0 == shaderProgHandle) {
		printf("ERROR creating shader programme\n");
		return false;
	}
	
	// attach shaders
	glAttachShader(shaderProgHandle, shaderAHandle);
	glAttachShader(shaderProgHandle, shaderBHandle);
	glAttachShader(shaderProgHandle, shaderCHandle);
	
	// link programme
	glLinkProgram(shaderProgHandle);
	
	// verify link status
	GLint status;
	glGetProgramiv(shaderProgHandle, GL_LINK_STATUS, &status);
	if (GL_FALSE == status) {
		printf("ERROR: failed to link shader programme\n");
		return false;
	}
	
	return true;
}

int ShaderHandler::UpdateUniform(const char* variable, GLuint shaderProgHandle, const void* value)
{
}