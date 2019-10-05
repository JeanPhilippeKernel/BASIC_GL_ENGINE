#pragma once
#include "Camera.h"
class OrbitCamera : public Camera
{
public:
	OrbitCamera();
	~OrbitCamera();

	void SetYaw(float yaw);
	void SetPitch(float pitch);

	void SetRadius(float radius);
	void SetTarget(glm::vec3 target);

	float GetPitch() const;
	float GetYaw() const;
	float GetRadius() const;
	
	void Rotate(float yaw, float pitch);

private:
	float m_yaw;
	float m_pitch;
	float m_radius;
};

