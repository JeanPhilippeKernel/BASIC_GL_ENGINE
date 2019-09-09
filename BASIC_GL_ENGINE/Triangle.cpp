#include "Triangle.h"

Triangle::Triangle(std::vector<Vertex>& const vertices)
	:Mesh(vertices)
{
	glGenVertexArrays(1, &(this->vertex_array_object));
	glGenBuffers(1, &(this->vertex_buffer_object));

	glBindVertexArray(this->vertex_array_object);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer_object);
	glBufferData(
		GL_ARRAY_BUFFER,
		this->VerticeByteSize(),
		this->m_raw_vertices.data(),
		GL_STATIC_DRAW
	);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid *)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Triangle::~Triangle()
{
	glDeleteBuffers(1, &(this->vertex_buffer_object));
	glDeleteVertexArrays(1, &(this->vertex_array_object));
}

void Triangle::Draw()
{
	glBindVertexArray(this->vertex_array_object);
	glDrawArrays(GL_TRIANGLES, 0, this->m_vertices.size());
	glBindVertexArray(0);
}
