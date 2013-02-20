#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_
#include "CommonIncludes.h"
#include "TextureLoader.h"

class GraphicsCore
{
	//Camera mCamera;
	//VAOModelLoader mVAOModel;
	//ShaderHandler mShader;
	TextureLoader mTexture;

	//void renderCallback();							    needed?
	//void resizeCallback(int width, int height);			window size
	//timer callback?										count fps
	//void Initialize();								    inialize glut stuff and general stuff.

public:
	GraphicsCore(void);
	~GraphicsCore(void);

	int RenderObject(unsigned int textureID, unsigned int modelID, unsigned int shaderID, vec3 color, float scale);
	int RenderObject(3DObject object);
	UINT LoadTexture(const char* file, UINT shaderProgHandle); 
	unsigned int LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, unsigned int shaderProgHandle); 
	unsigned int LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath, unsigned int shaderProgHandle); 
	unsigned int SendModel(vector<VertexPoint> vertexList); 
	unsigned int SendModel(vec3 position); 
 
	int UpdateCamera(vec3 eye, vec3 target, vec3 up); 
	int UpdateUniform(const char* variable, unsigned int shaderProgHandle, const void* value); 
};

#endif

