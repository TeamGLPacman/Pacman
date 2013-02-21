#ifndef CAMERA_H_
#define CAMERA_H_
#include "CommonIncludes.h"

class Camera
{
private:
	glm::vec3 eye;
	glm::vec3 centre; // orient camera to point towards a target position
	glm::vec3 up;
	glm::vec3 direction;
	glm::mat4 viewMatrix; // initialise to identity
	glm::mat4 modelMatrix;
	float hRadians;
	float vRadians;
public:
	Camera( );
	Camera( glm::vec3, glm::vec3, glm::vec3 );
	glm::mat4 GetViewMatrix ( glm::vec3, glm::vec3, glm::vec3 );
	//void SetPosition( );
	void Move( glm::vec3 );
	void Move( glm::vec3, float );
	void Rotate( float , glm::vec3 );
	void CameraAngle( float , float );
	glm::vec3 GetEye() { return eye; }

	glm::mat4 GetMVP ( int, int );  
};

#endif