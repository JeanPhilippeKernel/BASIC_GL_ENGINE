#include "Vertex.h"



Vertex::Vertex(float pos_x, float pos_y, float pos_z, float r, float g, float b, float a)
	:m_position(pos_x, pos_y, pos_z) , m_color(r, g, b)
{

}

Vertex::Vertex(Vector3f position, Vector3f color)
	:m_position(position), m_color(color)
{
}
											 