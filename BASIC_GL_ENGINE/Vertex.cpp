#include "Vertex.h"

//Vertex::Vertex(Vector3f const position, Vector3f const color)
//	:m_position(position), m_color(color)
//{
//}
//
//Vertex::~Vertex()
//{
//}
//
//const Vector3f& Vertex::GetPosition() const
//{
//	// TODO: insert return statement here
//	return this->m_position;
//}
//
//const Vector3f& Vertex::GetColor() const
//{
//	// TODO: insert return statement here
//	return this->m_color;
//}
//
//void Vertex::SetPosition(Vector3f& const position)
//{
//	this->m_position = position;
//}
//
//void Vertex::SetColor(Vector3f& const color)
//{
//	this->m_color = color;
//}
//
//



Vertex::Vertex(Vector3f const position, Vector3f const color)
	:m_position(position), m_color(color)
{
}

Vertex::~Vertex()
{
}

const Vector3f& Vertex::GetPosition() const
{
	return this->m_position;
}

const Vector3f& Vertex::GetColor() const
{
	return this->m_color;
}

void Vertex::SetPosition(Vector3f& const position)
{
	this->m_position = position;
}

void Vertex::SetColor(Vector3f& const color)
{
	this->m_color = color;
}
