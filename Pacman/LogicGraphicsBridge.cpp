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
uint LogicGraphicsBridge::LoadTexture(const char* texturePath){
	return mGraphics.LoadTexture(texturePath);
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
void LogicGraphicsBridge::RenderObject(Object3D *renderThis){
	mGraphics.RenderObject(renderThis);
}
void LogicGraphicsBridge::RenderObjects(vector<Object3D*> objects)
{
	mGraphics.RenderObjects(objects);
}
void LogicGraphicsBridge::EndRendering()
{
	mGraphics.EndRendering();
}
int LogicGraphicsBridge::UpdateCameraSmooth(vec3 eye, vec3 target, float speed){
	return mGraphics.UpdateCameraSmooth(eye, target, speed);
}

int LogicGraphicsBridge::UpdateCamera(vec3 eye, vec3 target){
	return mGraphics.UpdateCamera(eye, target);
}
int LogicGraphicsBridge::UpdateUniform(const char* variable, uint shaderProgHandle, float value)
{
	return mGraphics.UpdateUniform(variable, shaderProgHandle, value);
}
int LogicGraphicsBridge::UpdateUniform(const char* variable, uint shaderProgHandle, vec3 value)
{
	return mGraphics.UpdateUniform(variable, shaderProgHandle, value);
}

void LogicGraphicsBridge::TempCamUpdate()
{
	mGraphics.TempCamUpdate();
}