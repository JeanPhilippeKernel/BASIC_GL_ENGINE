#pragma once
#include "Camera.h"

class OrbitCamera : public Camera
{
public:
	explicit OrbitCamera(glm::vec3 position, glm::vec3 target, float yaw, float pitch);
	virtual ~OrbitCamera() = default;


	virtual void UpdateVectors() override;

};

