#include "Camera.h"

Camera::Camera() 
	:m_position(glm::vec3(0.0f, 0.0f, 0.0f)), m_target(glm::vec3(0.0f, 0.0f, 0.0f)), m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
	m_pitch(0.0f), m_yaw(0.0f), m_radius(10.0f)
{
	this->__defaultRotate();
}

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
	:m_position(position), m_target(target), m_up(up),
	m_yaw(0.0f), m_pitch(0.0f),m_radius(10.0f)
{
	this->__defaultRotate();
}

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float pitch, float yaw)
	:m_position(position), m_target(target), m_up(up),
	 m_radius(10.0f), m_yaw(0.0f), m_pitch(0.0f)
{
	this->SetYawAngle(yaw);
	this->SetPitchAngle(pitch);
	this->__defaultRotate();
}


Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float radius, float pitch, float yaw)
	:m_position(position), m_target(target), m_up(up),
	m_radius(radius), m_yaw(0.0f), m_pitch(0.0f)
{
	this->SetYawAngle(yaw);
	this->SetPitchAngle(pitch);
	this->__defaultRotate();
}

const glm::vec3& Camera::GetPosition() const 
{
	return this->m_position;
}

const glm::vec3& Camera::GetTarget() const
{
	return this->m_target;
}

const glm::vec3& Camera::GetUp() const
{
	return this->m_up;
}

float Camera::GetPitchAngle() const
{
	return m_pitch;
}
float Camera::GetYawAngle() const
{
	return m_yaw;
}
float Camera::GetRadius() const
{
	return m_radius;
}

void Camera::SetPosition(glm::vec3 position)
{
	this->m_position = position;
}
void Camera::SetTarget(glm::vec3 target)
{
	this->m_target = target;
}
	
void Camera::SetPitchAngle(float pitch)
{
	this->m_pitch = glm::radians(pitch);
	this->m_pitch = glm::clamp(this->m_pitch, -glm::half_pi<float>() + 0.1f, glm::half_pi<float>() - 0.1f);

}
void Camera::SetYawAngle(float yaw)
{
	this->m_yaw = glm::radians(yaw);
}

void Camera::SetRadius(float radius) 
{
	this->m_radius = radius;
}


void Camera::__defaultRotate()
{
	this->m_position.x = this->m_target.x + (m_radius * std::cos(m_pitch) * std::sin(m_yaw));
	this->m_position.y = this->m_target.y + (m_radius * std::sin(m_pitch));
	this->m_position.z = this->m_target.z + (m_radius * std::cos(m_pitch) * std::cos(m_yaw));
}


glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(this->m_position, this->m_target, this->m_up);
}