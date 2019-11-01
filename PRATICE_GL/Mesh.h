#pragma once

#include <vector>
#include <GL/glew.h>
#include <algorithm>

#include "Vertex.h"
#include "Texture2D.h"


class Mesh
{
public:
	explicit Mesh(std::vector<Vertex> vertices);
	explicit Mesh(const char * texture_filename, std::vector<Vertex> vertices);
	explicit Mesh(const char * obj_file);


	virtual ~Mesh();

	void Draw();

private:
	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

	std::vector<float> m_raw_vertices;

	Texture2D m_texture;
};

