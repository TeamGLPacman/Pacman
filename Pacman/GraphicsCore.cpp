#include "GraphicsCore.h"


GraphicsCore::GraphicsCore(void)
{
}

GraphicsCore::~GraphicsCore(void)
{
}

int GraphicsCore::RenderObject(unsigned int textureID, unsigned int modelID, unsigned int shaderID, vec3 color, float scale)
{
}

int GraphicsCore::RenderObject(3DObject object)
{
}

UINT GraphicsCore::LoadTexture(const char* file, UINT shaderProgHandle)
{
	return mTexture.LoadTexture_TGA(file, shaderProgHandle);
}

unsigned int GraphicsCore::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, unsigned int shaderProgHandle)
{
}

unsigned int GraphicsCore::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath, unsigned int shaderProgHandle)
{
}

unsigned int GraphicsCore::SendModel(vector<VertexPoint> vertexList)
{
}

unsigned int GraphicsCore::SendModel(vec3 position)
{
}
 
int GraphicsCore::UpdateCamera(vec3 eye, vec3 target, vec3 up)
{
}

int GraphicsCore::UpdateUniform(const char* variable, unsigned int shaderProgHandle, const void* value)
{
}