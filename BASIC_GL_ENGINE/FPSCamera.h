#pragma once
#include "Camera.h"


class FPSCamera : public Camera
{
public:
	FPSCamera(glm::vec3 position, glm::vec3 target, float yaw, float pitch);
	~FPSCamera() =  default;

	virtual void Move(glm::vec3 offsetPostion);
	virtual void Rotate(float yaw, float pitch) override;
	virtual void Update() override;
};

