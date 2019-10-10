#pragma once
#include "Camera.h"
class OrbitCamera : public Camera
{
public:
	OrbitCamera(glm::vec3 target, float radius, float yaw, float pitch);
	virtual ~OrbitCamera();

	virtual void UpdatePosition();
};	

