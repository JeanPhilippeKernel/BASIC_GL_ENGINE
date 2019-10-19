#include "FPSCamera.h"
#include <iostream>

FPSCamera::FPSCamera(glm::vec3 position, glm::vec3 target, float yaw, float pitch)
	: Camera(position, target, glm::vec3(0.f, 1.0f, 0.0f), pitch, yaw)
{
}

void FPSCamera::Move(glm::vec3 offsetPostion)
{
	m_position += offsetPostion;
	Update();
}

void FPSCamera::Rotate(float yaw, float pitch)
{
	m_yaw += glm::radians(yaw);
	m_pitch += glm::radians(pitch);
	m_pitch = glm::clamp(m_pitch, -glm::pi<float>() / 2.0f + 0.1f, glm::pi<float>() / 2.0f - 0.1f);

	Update();

	//Camera::Update();
}

void FPSCamera::Update()
{
	glm::vec3 _forward;

	_forward.x = (std::cosf(m_pitch) * std::sinf(m_yaw));
	_forward.y = (std::sinf(m_pitch));
	_forward.z = (std::cosf(m_pitch) * std::cosf(m_yaw));
	this->m_forward = glm::normalize(_forward);

	m_right = glm::normalize(glm::cross(this->m_forward, WORLD_UP));
	m_up = glm::normalize(glm::cross(m_right, this->m_forward));

	m_target = m_position + m_forward;

}
