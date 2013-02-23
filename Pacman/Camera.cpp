#include "Camera.h"


Camera::Camera(){
	eye = glm::vec3(0.0f, 0.0f, -1.0f);
	centre = glm::vec3(0.0f, 0.0f, 0.0f); 
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	viewMatrix = glm::mat4(1.0f);
	modelMatrix = glm::mat4(1.0f); 
}

Camera::Camera( glm::vec3 _eye, glm::vec3 _centre, glm::vec3 _up){
	eye = _eye;
	centre = _centre;
	direction = glm::normalize(centre - eye);
	up = _up; 
	viewMatrix = glm::mat4(1.0f);
	modelMatrix = glm::mat4(1.0f);
}

glm::mat4 Camera::GetViewMatrix(glm::vec3 _eye, glm::vec3 _center, glm::vec3 up ){

	centre = eye + direction;

	glm::vec3 dir = glm::normalize(_center - eye);
	glm::vec3 tup = glm::normalize(up);
	glm::vec3 s = glm::normalize(glm::cross(dir, tup));
	tup = glm::cross(s, dir);

	glm::mat4x4 Result(1);
        Result[0][0] = s.x;
        Result[1][0] = s.y;
        Result[2][0] = s.z;
        Result[0][1] = tup.x;
        Result[1][1] = tup.y;
        Result[2][1] = tup.z;
        Result[0][2] =-dir.x;
        Result[1][2] =-dir.y;
        Result[2][2] =-dir.z;

		return glm::translate(Result, -eye);
}

glm::mat4 Camera::GetMVP (int windowHeight, int windowWidth){
	
	viewMatrix = GetViewMatrix(eye, centre, up); // this function is similar to one from the older opengl

	glm::mat4 modelViewMatrix = viewMatrix * modelMatrix;

	float n = 1;
	float f = 2000;
	float fov = 60 * (3.14 / 180); 

	float e = 1 / glm::tan(fov / 2);

	float a = windowHeight / (float)windowWidth;

	glm::mat4 projectionMatrix = glm::mat4(
		e, 0, 0, 0,
		0, e/a, 0, 0,
		0, 0, -(f + n) / (f - n), -(2 * f * n)/(f - n),
		0, 0, -1, 0);

	glm::mat4 modelViewProjectionMatrix = projectionMatrix * modelViewMatrix;
	
	return modelViewProjectionMatrix;
}

void Camera::Rotate( float angle, glm::vec3 rotateVector){
	modelMatrix = glm::rotate(modelMatrix, angle, rotateVector);
}

void Camera::Move( glm::vec3 delta ){
	eye += direction;
	//centre = eye + delta;
}

void Camera::Move( glm::vec3 delta, float  yPos ){
	if (delta.x != 0){
		eye += direction * 0.1f * delta.x;
	}
	else if ( delta.y != 0){
		glm::vec3 str = direction;

		str.x = cos(hRadians+3.14/2) ; 
		str.y = 0;
		str.z = sin(hRadians+3.14/2) ; 

		str = glm::normalize(str);

		eye += str * 0.1f * delta.y;
	}
	eye.y = yPos-1;
	centre.y = eye.y;
}

void Camera::CameraAngle( float x, float y ){
	
	hRadians += x  ;//* 3.14f / 180; 
	//vRadians += y * 3.14f / 180; 

	direction.x = cos(hRadians) ; 
	direction.y = 0;
	direction.z = sin(hRadians) ; 

	direction = glm::normalize(direction);
}
