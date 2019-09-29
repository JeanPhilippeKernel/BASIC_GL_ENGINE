#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


class Camera
{
public:
	Camera() = default;
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);
	virtual ~Camera() =  default;

	const glm::vec3& GetPosition() const { return this->m_position;  }
	const glm::vec3& GetTarget() const { return this->m_target; }
	const glm::vec3& GetUp() const { return this->m_up; }

	virtual glm::mat4 GetViewMatrix() const = 0;

protected:
	glm::vec3 m_position;
	glm::vec3 m_target;
	glm::vec3 m_up;
};

