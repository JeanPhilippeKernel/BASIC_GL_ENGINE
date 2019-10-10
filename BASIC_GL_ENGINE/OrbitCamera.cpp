#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(glm::vec3 target, float radius, float yaw, float pitch)
	:Camera()
{
	this->m_target = target;
	this->m_radius =  radius;
	this->m_yaw = yaw;
	this->m_pitch = pitch;
}


void OrbitCamera::Rotate(float yaw, float pitch)
{
	this->__defaultRotate(yaw, pitch);
}
