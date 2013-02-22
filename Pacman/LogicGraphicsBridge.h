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
	uint LoadTexture(const char* texturePath, uint shaderProgHandle);
	uint SendModel(vector<VertexPoint> vertexList);
	uint SendModel(vec3 position); 
	
	void BeginRendering();
	void RenderObject(uint textureID, uint modelID, uint shaderID, vec3 color, float scale);
	void RenderObject(Object3D renderThis);
	void EndRendering();

	int UpdateCamera(vec3 eye, vec3 target, vec3 up);
	int UpdateUniform(const char* variable, uint shaderProgHandle, float value);
	int UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value);
};
#endif