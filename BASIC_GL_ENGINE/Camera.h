#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/constants.hpp>


class Camera
{
public:
	Camera();
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float pitch, float yaw);
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float radius, float pitch, float yaw);
	virtual ~Camera() =  default;

	const glm::vec3& GetPosition() const;
	const glm::vec3& GetTarget() const;
	const glm::vec3& GetUp() const;

	float GetPitchAngle() const;
	float GetYawAngle() const;
	float GetRadius() const;

	void SetPosition(glm::vec3 position);
	void SetTarget(glm::vec3 target);
	
	void SetPitchAngle(float pitch);
	void SetYawAngle(float yaw);
	void SetRadius(float radius);

	

	virtual void Rotate(float yaw, float pitch) = 0;

	glm::mat4 GetViewMatrix() const;

protected:
	glm::vec3 m_position;
	glm::vec3 m_target;
	glm::vec3 m_up;

	float m_pitch;
	float m_yaw;
	float m_radius;

	void __defaultRotate(float yaw, float pitch);
};

