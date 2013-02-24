#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_
#include "CommonIncludes.h"
#include "TextureLoader.h"
#include "ShaderHandler.h"
#include "VAOModelLoader.h"
#include "TempCam.h"

//void resizeCallback(int width, int height);	
//timer callback?							count fps



class GraphicsCore
{
private:
	
	float fov;
	char* windowTitle;
	//Camera mCamera;
	TempCam mCam;
	VAOModelLoader mVAOModel;
	ShaderHandler mShader;
	TextureLoader mTexture;

	//temporary
	void tempValues(uint shaderProgHandle, Object3D object);

public:
	GraphicsCore(void);
	~GraphicsCore(void);

	uint Initialize(int argc, char** argv);
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath); 
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath); 
	uint LoadTexture(const char* file); 
	uint SendModel(vector<VertexPoint> vertexList); 
	uint SendModel(vec3 position); 

	void close() {exit(0);}
	void BeginRendering();
	void RenderObject(uint textureID, uint modelID, uint shaderID, vec3 color, float scale);
	void RenderObject(Object3D object);
	void EndRendering();
 
	int UpdateCamera(vec3 eye, vec3 target, vec3 up); 
	int UpdateUniform(const char* variable, uint shaderProgHandle, float value);
	int UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value);

	void TempCamUpdate();
};

#endif

