#include "Mesh.h"



Mesh::Mesh(std::vector<Vertex> vertices)
	:m_VAO(0), m_VBO(0), m_EBO(0)
{

	std::for_each(vertices.begin(), vertices.end(),
		[this](const Vertex& v)
		{
			m_raw_vertices.push_back(v.Get_Position().Get_X());
			m_raw_vertices.push_back(v.Get_Position().Get_Y());
			m_raw_vertices.push_back(v.Get_Position().Get_Z());
		});



	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(this->m_VAO);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->m_raw_vertices.size(), this->m_raw_vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (6 * sizeof(float)), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (6 * sizeof(float)), (void*)(3 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


Mesh::Mesh(std::string obj_file)
	:m_VAO(0), m_VBO(0), m_EBO(0)
{
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}

void Mesh::Draw()
{
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, m_raw_vertices.size());
	glBindVertexArray(0);
}