#pragma once
#include <glm/glm.hpp>
#include "Vector3f.h"
#include "Vector2f.h"

//class Vertex
//{
//public:
//	Vertex(glm::vec3 const position, glm::vec3 const color);
//	virtual ~Vertex();
//
//
//	const glm::vec3& GetPosition() const;
//	const glm::vec3& GetColor() const;
//
//	void SetPosition(glm::vec3& const position);
//	void SetColor(glm::vec3& const color);
//
//private:
//	glm::vec3 m_position;
//	glm::vec3 m_color;
//
//};




struct Vertex
{
public:
	Vertex(Vector3f const position, Vector3f const color, Vector2f const texture);
	virtual ~Vertex();

	const Vector3f& GetPosition() const;
	const Vector3f& GetColor() const;
	const Vector2f& GetTexture() const;

	void SetPosition(Vector3f& const position);
	void SetColor(Vector3f& const color);
	void SetTexture(Vector2f& const texture);

private:
	Vector3f m_position;
	Vector3f m_color;
	Vector2f m_texture;
};

