#pragma once

struct Vector2f
{
	float m_x, m_y;
	Vector2f() = default;
	Vector2f(float x, float y) : m_x(x), m_y(y) {}

	float Get_X() const { return m_x; }
	float Get_Y() const { return m_y; }
};
