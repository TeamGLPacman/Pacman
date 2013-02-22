#include "LogicGraphicsBridge.h"


LogicGraphicsBridge::LogicGraphicsBridge(void)
{
}
LogicGraphicsBridge::~LogicGraphicsBridge(void)
{
}

uint LogicGraphicsBridge::Initialize(int argc, char** argv)
{
	return mGraphics.Initialize(argc, argv);
}
uint LogicGraphicsBridge::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath){
	return mGraphics.LoadShaderFiles(vertexShaderPath, fragmentShaderPath);
}
uint LogicGraphicsBridge::LoadShaderFiles(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath){
	return mGraphics.LoadShaderFiles(vertexShaderPath, fragmentShaderPath, geometryShaderPath);
}
uint LogicGraphicsBridge::LoadTexture(const char* texturePath, uint shaderProgHandle){
	return mGraphics.LoadTexture(texturePath, shaderProgHandle);
}
uint LogicGraphicsBridge::SendModel(vector<VertexPoint> vertexList){
	return mGraphics.SendModel(vertexList);
}
uint LogicGraphicsBridge::SendModel(vec3 position)
{
	return mGraphics.SendModel(position);
}

void LogicGraphicsBridge::BeginRendering()
{
	mGraphics.BeginRendering();
}
void LogicGraphicsBridge::RenderObject(uint textureID, uint modelID, uint shaderID, vec3 color, float scale){
	mGraphics.RenderObject(textureID, modelID, shaderID, color, scale);
}
void LogicGraphicsBridge::RenderObject(Object3D renderThis){
	mGraphics.RenderObject(renderThis);
}
void LogicGraphicsBridge::EndRendering()
{
	mGraphics.EndRendering();
}

int LogicGraphicsBridge::UpdateCamera(vec3 eye, vec3 target, vec3 up){
	return mGraphics.UpdateCamera(eye, target, up);
}
int LogicGraphicsBridge::UpdateUniform(const char* variable, uint shaderProgHandle, float value)
{
	return mGraphics.UpdateUniform(variable, shaderProgHandle, value);
}
int LogicGraphicsBridge::UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value)
{
	return mGraphics.UpdateUniform(variable, shaderProgHandle, value);
}