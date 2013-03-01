#ifndef TEMPCAM_H
#define TEMPCAM_H
#include "CommonIncludes.h"

#define _USE_MATH_DEFINES
#include <cmath>

class TempCam
{
private:

	int mouseX, mouseY;
	float camX, camY, camZ;
	float camYaw;
	float camPitch;

public:
	
	TempCam(void);
	~TempCam(void);

	void lockCamera();
	void moveCamera(float, float);
	void moveCameraUp(float, float);
	void Control(float moveVel, float mouseSense, bool mi);
	float GetYaw();
	float GetPitch();
	void SetPitch(float pitch);
	void SetYaw(float yaw);
	glm::vec3 GetCamPos();
	glm::mat4 GetRotationMatrix();
};

#endif

