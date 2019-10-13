#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/constants.hpp>


class Camera
{
public:
	Camera() =  delete;
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float pitch, float yaw);
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float radius, float pitch, float yaw);
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float fov, float radius, float pitch, float yaw);
	virtual ~Camera() =  default;

	const glm::vec3& GetPosition() const;
	const glm::vec3& GetTarget() const;
	const glm::vec3& GetUp() const;

	const glm::vec3& GetForward() const;
	const glm::vec3& GetRigth() const;

	float GetPitchAngle() const;
	float GetYawAngle() const;
	float GetRadius() const;
	float GetFov() const;

	void SetPosition(glm::vec3 position);
	void SetTarget(glm::vec3 target);
	void SetUp(glm::vec3 up);
	
	void SetForward(glm::vec3 forward);
	void SetRight(glm::vec3 right);

	void SetPitchAngle(float pitch);
	void SetYawAngle(float yaw);
	void SetRadius(float radius);

	void SetFov(float fieldOfView);

	virtual void Rotate(float yaw, float pitch);

	glm::mat4 GetViewMatrix() const;

protected:
	glm::vec3 m_position;
	glm::vec3 m_target;
	glm::vec3 m_up;

	glm::vec3 m_forward;
	glm::vec3 m_right;

	float m_pitch;
	float m_yaw;
	float m_radius;

	float m_fov{ 45.0f };
	
	virtual void Update();

	const glm::vec3 WORLD_UP{ glm::vec3(0.f, 1.0f, 0.0f) };
private:
};

