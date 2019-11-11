#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(glm::vec3 position, glm::vec3 target, float yaw_angle, float pitch_angle)
{
	m_position = position;
	m_target = target;
	m_yaw_angle = glm::radians(yaw_angle);
	
	m_pitch_angle = glm::clamp(glm::radians(pitch_angle), -glm::half_pi<float>() + 1.0f, glm::half_pi<float>() - 1.0f);
	
	auto distance = position - target;
	m_radius = std::sqrtf((distance.x * distance.x) + (distance.y * distance.y) + (distance.z * distance.z));

	UpdateVectors();
}

void OrbitCamera::UpdateVectors()
{
	glm::vec3 look;

	look.x = m_radius * std::cosf(m_pitch_angle) * std::sinf(m_yaw_angle);
	look.y = m_radius * std::sinf(m_pitch_angle);
	look.z = m_radius * std::cosf(m_pitch_angle) * std::cosf(m_yaw_angle);

	m_position.x = m_target.x + look.x;
	m_position.y = m_target.y + look.y;
	m_position.z = m_target.z + look.z;

	m_forwad = glm::normalize(m_position - m_target);
	m_right = glm::normalize(glm::cross(WORLD_UP, m_forwad));
	m_up = glm::normalize(glm::cross(m_forwad, m_right));

}
