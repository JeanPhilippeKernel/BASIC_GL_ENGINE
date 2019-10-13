#include "Camera.h"

//Camera::Camera() 
//	:m_position(glm::vec3(0.0f, 0.0f, 0.0f)), m_target(glm::vec3(0.0f, 0.0f, 0.0f)), m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
//	m_pitch(0.0f), m_yaw(0.0f), m_radius(0.0f)
//{
//}

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
	:m_position(position), m_target(target), m_up(up),
	m_yaw(0.0f), m_pitch(0.0f),m_radius(0.0f)
{
	auto v = m_position - m_target;
	m_radius = std::sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float pitch, float yaw)
	:Camera(position, target, up)
{
	auto v = m_position - m_target;
	m_radius = std::sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	
	SetYawAngle(yaw);
	SetPitchAngle(pitch);
}


Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float radius, float pitch, float yaw)
	:Camera(position, target, up)
{
	SetRadius(radius);
	SetYawAngle(yaw);
	SetPitchAngle(pitch);
}

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float fov, float radius, float pitch, float yaw)
	:Camera(position, target, up, radius, pitch, yaw)
{
	SetFov(fov);
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

const glm::vec3 & Camera::GetForward() const
{
	return this->m_forward;
}

const glm::vec3 & Camera::GetRigth() const
{	
	return this->m_right;
}

float Camera::GetPitchAngle() const
{
	return glm::degrees(m_pitch);
}
float Camera::GetYawAngle() const
{
	return glm::degrees(m_yaw);
}
float Camera::GetRadius() const
{
	return m_radius;
}

float Camera::GetFov() const
{
	return m_fov;
}

void Camera::SetPosition(glm::vec3 position)
{
	this->m_position = position;
}
void Camera::SetTarget(glm::vec3 target)
{
	this->m_target = target;
}

void Camera::SetUp(glm::vec3 up)
{
	this->m_up = up;
}

void Camera::SetForward(glm::vec3 forward)
{
	this->m_forward = forward;
}

void Camera::SetRight(glm::vec3 right)
{
	this->m_right = right;
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
	this->m_radius = glm::clamp(radius, 2.f, 80.f);

}

void Camera::SetFov(float fieldOfView)
{
	this->m_fov = glm::clamp(fieldOfView, 1.0f, 120.0f);
}

void Camera::Rotate(float yaw, float pitch)
{
	Update();
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(this->m_position, this->m_target, this->m_up);
}

void Camera::Update()
{
	m_forward = glm::normalize(m_position - m_target);
	m_right = glm::normalize(glm::cross(WORLD_UP, m_forward));
	m_up = glm::cross(m_forward, m_right);
}
