#pragma once
#include "Camera.h"


class FreeCamera : public Camera
{
public: 
	FreeCamera(glm::vec3 position, glm::vec3 target, glm::vec3 up);
	virtual ~FreeCamera() = default;

};

