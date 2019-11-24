#pragma once

#include <vector>
#include <GL/glew.h>
#include <algorithm>

#include "Vertex.h"

#include "ObjParser.h"

class Mesh
{
public:
	Mesh() = default;
	explicit Mesh(std::vector<Vertex> vertices);
	
	virtual ~Mesh();

	void LoadOBJFile(const char * filename);
	void Draw();

private:
	Mesh(const Mesh&);
	
	GLuint m_VAO{ 0 };
	GLuint m_VBO{ 0 };
	GLuint m_EBO{ 0 };

	std::vector<float> m_raw_vertices;
};

