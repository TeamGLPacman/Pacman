#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_
#include "CommonIncludes.h"
#include "TextureLoader.h"
#include "ShaderHandler.h"
#include "VAOModelLoader.h"

int windowWidth, windowHeight;
void renderCallback();
void resizeCallback(int width, int height);	
//timer callback?							count fps

class GraphicsCore
{
private:
	char* windowTitle;
	//Camera mCamera;
	VAOModelLoader mVAOModel;
	ShaderHandler mShader;
	TextureLoader mTexture;

public:
	GraphicsCore(void);
	~GraphicsCore(void);

	uint Initialize(int argc, char** argv);
	int RenderObject(unsigned int textureID, unsigned int modelID, unsigned int shaderID, vec3 color, float scale);
	int RenderObject(Object3D object);
	uint LoadTexture(const char* file, UINT shaderProgHandle); 
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, unsigned int shaderProgHandle); 
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath, unsigned int shaderProgHandle); 
	uint SendModel(vector<VertexPoint> vertexList); 
	uint SendModel(vec3 position); 
 
	int UpdateCamera(vec3 eye, vec3 target, vec3 up); 
	int UpdateUniform(const char* variable, unsigned int shaderProgHandle, const void* value); 
};

#endif

