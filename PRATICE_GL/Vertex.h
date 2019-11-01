#pragma once
#include <glm/glm.hpp>
#include "Vector3f.h"


class Vertex
{	
public:
	Vertex() = default;
	Vertex(float pos_x, float pos_y, float pos_z, float r, float g, float b, float a);
	Vertex(Vector3f position, Vector3f color);
	
	~Vertex() = default;

	const Vector3f& Get_Position() const { return m_position; }
	const Vector3f& Get_Color() const { return m_color; }

private:
	Vector3f m_position;
	Vector3f m_color;
};

