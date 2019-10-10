#pragma once
#include "Camera.h"
class OrbitCamera : public Camera
{
public:
	OrbitCamera(glm::vec3 target, float radius, float yaw, float pitch);
	~OrbitCamera();

	virtual void Rotate(float yaw, float pitch) override;
};

