#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include <GL/glew.h>

#include "Vertex.h"

class Mesh
{

public:
	Mesh(std::vector<Vertex>& const vertices);
	virtual ~Mesh();


	virtual void Draw() = 0;


protected:
	GLuint vertex_array_object;
	GLuint vertex_buffer_object;
	GLuint element_buffer_array;

	std::vector<Vertex> m_vertices;
	std::vector<float> m_raw_vertices;


	GLsizei VerticeByteSize() const;
	
};

