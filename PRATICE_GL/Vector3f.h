#pragma once
struct Vector3f
{
	float m_x, m_y, m_z;
	Vector3f(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}

	float Get_X() const { return m_x; }
	float Get_Y() const { return m_y; }
	float Get_Z() const { return m_z; }
};

