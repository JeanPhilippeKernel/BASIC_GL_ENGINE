#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(glm::vec3 position, glm::vec3 target, float yaw, float pitch)
	:Camera(position, target, glm::vec3(0, 1, 0), pitch, yaw)

{
}

void OrbitCamera::Rotate(float yaw, float pitch)
{
	SetYawAngle(yaw);
	SetPitchAngle(pitch);

	this->m_position.x = this->m_target.x + (m_radius * std::cos(m_pitch) * std::sin(m_yaw));
	this->m_position.y = this->m_target.y + (m_radius * std::sin(m_pitch));
	this->m_position.z = this->m_target.z + (m_radius * std::cos(m_pitch) * std::cos(m_yaw));

	Camera::Update();
}


