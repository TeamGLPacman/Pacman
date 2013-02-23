#include "TempCam.h"


#ifndef M_PI
#define M_PI 3.14159265
#endif


bool mousein = false;

TempCam::TempCam(void)
{
	camX = 0.0, camY = 2.0, camZ = 0.0;
	camYaw = 0.0;
	camPitch = 0.0;
}

TempCam::~TempCam(void)
{
}

void TempCam::lockCamera()
{
	if(camPitch > 90)
		camPitch = 90;
	if(camPitch < -90)
		camPitch = -90;
	if(camYaw < 0.0)
		camYaw += 360;
	if(camYaw > 360)
		camYaw -= 360;
}

void TempCam::moveCamera(float dist, float dir)
{
	float rad = (camYaw + dir)*M_PI/180.0;
	camX -= sin(rad)*dist;
	camZ -= cos(rad)*dist;
}

void TempCam::moveCameraUp(float dist, float dir)
{
	float rad = (camPitch+dir)*M_PI/180.0;
	camY += sin(rad)*dist;
}

void TempCam::SetMousePos(int x, int y)
{
	mouseX = x;
	mouseY = y;
}

void TempCam::Control(float moveVel, float mouseSens, bool mi, float midX, float midY)
{
	if(mi)
	{
		camYaw += mouseSens*(midX-mouseX);
		camPitch += mouseSens*(midY-mouseY);
		lockCamera();
		glutWarpPointer(midX, midY);
		if(GetAsyncKeyState('W') != 0)
		{
			if(camPitch!=90 && camPitch != -90)
				moveCamera(moveVel, 0.0);
				moveCameraUp(moveVel, 0.0);
		}
		else if(GetAsyncKeyState('S') != 0)
		{
			if(camPitch!=90 && camPitch != -90)
				moveCamera(moveVel, 180.0);
				moveCameraUp(moveVel, 180.0);
		}

		if(GetAsyncKeyState('A') != 0)
		{
			moveCamera(moveVel, 90.0);
		}
		else if(GetAsyncKeyState('D') != 0)
		{
			moveCamera(moveVel, 270.0);
		}
	}

}

float TempCam::GetPitch()
{
	return camPitch;
}

float TempCam::GetYaw()
{
	return camYaw;
}

glm::vec3 TempCam::GetCamPos()
{
	return glm::vec3(camX, camY, camZ);
}

void TempCam::SetYPos(float y)
{
	camY = y;
}

glm::mat4 TempCam::GetRotationMatrix()
{
	return glm::rotate(-GetPitch(), 1.0f, 0.0f, 0.0f) * glm::rotate(-GetYaw(), 0.0f, 1.0f, 0.0f);
}