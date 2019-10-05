#include "OrbitCamera.h"

OrbitCamera::OrbitCamera()
	:m_radius(0.0f), m_yaw(0.0f), m_pitch(0.0f), 
	Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
{
}

OrbitCamera::~OrbitCamera()
{
}

void OrbitCamera::SetYaw(float yaw)
{
	this->m_yaw = yaw;
}

void OrbitCamera::SetPitch(float pitch)
{
	this->m_pitch = pitch;
}

void OrbitCamera::SetRadius(float radius)
{
	this->m_radius = radius;
}

void OrbitCamera::SetTarget(glm::vec3 target)
{
	this->m_target = target;
}

float OrbitCamera::GetPitch() const
{
	return this->m_pitch;
}

float OrbitCamera::GetYaw() const
{
	return this->m_yaw;
}

float OrbitCamera::GetRadius() const
{
	return this->m_radius;
}



glm::mat4 OrbitCamera::GetViewMatrix() const
{
	return glm::lookAt(this->m_position, this->m_target, this->m_up);
}

void OrbitCamera::Rotate(float yaw, float pitch)
{
	m_yaw = glm::radians(yaw);
	m_pitch = glm::radians(pitch);

	m_pitch = glm::clamp(m_pitch, -glm::half_pi<float>() + 0.1f, glm::half_pi<float>() - 0.1f);

	m_position.x = (m_radius * std::cos(m_pitch) * std::sin(m_yaw)) + m_target.x;
	m_position.y = (m_radius * std::sin(m_pitch)) + m_target.y;
	m_position.z = (m_radius * std::cos(m_pitch) * std::cos(m_yaw)) + m_target.z;
}
