#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera() = default;
	virtual ~Camera() = default;


	float Get_Yaw_Angle() const { return m_yaw_angle; }
	float Get_Pitch_Angle() const { return m_pitch_angle; }
	float Get_Radius() const { return m_radius; }

	void Set_Radius(float radius) { m_radius = radius; }
	void Set_Yaw_Angle(float angle) { m_yaw_angle = glm::radians(angle); }
	void Set_Pitch_Angle(float angle) { m_pitch_angle = glm::clamp(glm::radians(angle), -glm::half_pi<float>() + 1.0f, glm::half_pi<float>() - 1.0f); }

	virtual void UpdateVectors() = 0;

	const glm::mat4 ToMatrix() const { return glm::lookAt(m_position, m_right, m_up); }

protected:
	float m_yaw_angle{ 0.0f };
	float m_pitch_angle{ 0.0f };
	float m_radius{ 10.f };

	float m_field_of_view{ 45.0f };


	glm::vec3 m_forwad{ 0.0f };
	glm::vec3 m_right{ 0.0f };
	glm::vec3 m_up{ 0.0f };


	glm::vec3 m_position{ 0.0f };
	glm::vec3 m_target{ 0.0f };


	const glm::vec3 WORLD_UP{ 0.0f, 1.0f, 0.0f };
};

