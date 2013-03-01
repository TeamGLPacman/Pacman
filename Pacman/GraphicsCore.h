#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_
#include "CommonIncludes.h"
#include "TextureLoader.h"
#include "ShaderHandler.h"
#include "VAOModelLoader.h"
#include "TempCam.h"
#include "wtypes.h"
#include <iostream>



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

	vec3 mEye;
	vec3 mTarget;

	void GetDesktopResolution(int& Width, int& Heigth);
public:
	GraphicsCore(void);
	~GraphicsCore(void);
	
	uint Initialize(int argc, char** argv);
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath); 
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath); 
	uint LoadTexture(const char* file);
	uint SendModel(vector<VertexPoint> vertexList);
	uint SendModel(vec3 position);

	void UpdateLightValues(Object3D object);
	void UpdateBillboardObjectValues(Object3D object);
	void UpdateObjectValues(Object3D);
	void close() {exit(0);}
	void BeginRendering();
	void RenderObject(Object3D *object);
	void RenderObjects(vector<Object3D*> objects);
	void EndRendering();
 
	int UpdateCamera(vec3 eye, vec3 target); 
	int UpdateUniform(const char* variable, uint shaderProgHandle, float value);
	int UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value);

	void TempCamUpdate();
};

#endif

