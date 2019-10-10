#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(glm::vec3 target, float radius, float yaw, float pitch)
	:Camera(glm::vec3(0, 0, 0), target, glm::vec3(0, 1, 0), radius, pitch, yaw)

{

}

OrbitCamera::~OrbitCamera()
{
}

void OrbitCamera::UpdatePosition()
{
	this->m_position.x = this->m_target.x + (m_radius * std::cos(m_pitch) * std::sin(m_yaw));
	this->m_position.y = this->m_target.y + (m_radius * std::sin(m_pitch));
	this->m_position.z = this->m_target.z + (m_radius * std::cos(m_pitch) * std::cos(m_yaw));
}
