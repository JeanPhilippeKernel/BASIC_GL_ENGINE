#include "FreeCamera.h"

FreeCamera::FreeCamera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
	:Camera(position, target, up)
{
}

glm::mat4 FreeCamera::GetViewMatrix() const
{
	return glm::lookAt(this->m_position, this->m_target, this->m_up);
}
