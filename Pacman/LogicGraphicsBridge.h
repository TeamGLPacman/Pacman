#ifndef LOGICGRAPHICSBRIDGE_H_
#define LOGICGRAPHICSBRIDGE_H_

#include "GraphicsCore.h"
#include "CommonIncludes.h"

class LogicGraphicsBridge
{
private:
	GraphicsCore mGraphics;
public:
	LogicGraphicsBridge(void);
	~LogicGraphicsBridge(void);
	
	uint Initialize(int argc, char** argv);
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath);
	uint LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath);
	uint LoadTexture(const char* texturePath);
	uint SendModel(vector<VertexPoint> vertexList);
	uint SendModel(vec3 position); 
	
	void BeginRendering();
	void RenderObjects(vector<Object3D*> objects);
	void RenderObject(Object3D *renderThis);
	void EndRendering();

	int UpdateCameraSmooth(vec3 eye, vec3 target, float speed);
	int UpdateCamera(vec3 eye, vec3 target);
	int UpdateUniform(const char* variable, uint shaderProgHandle, float value);
	int UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value);
	void TempCamUpdate();
};
#endif