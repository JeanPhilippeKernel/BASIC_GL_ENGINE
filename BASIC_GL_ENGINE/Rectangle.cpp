#include "Rectangle.h"

Rectangle::Rectangle(std::vector<Vertex>& const vertices)
	:Mesh(vertices), m_index({0, 1, 3, 1, 2, 3})
{
	glGenVertexArrays(1, &(this->vertex_array_object));
	glGenBuffers(1, &(this->vertex_buffer_object));
	glGenBuffers(1, &(this->element_buffer_array));


	glBindVertexArray(this->vertex_array_object);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer_object);
	glBufferData(GL_ARRAY_BUFFER, this->VerticeByteSize(), this->m_raw_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->element_buffer_array);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_index.size() * sizeof(unsigned int), this->m_index.data(), GL_STATIC_DRAW);
	

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(3 * sizeof(float)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(6* sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Rectangle::~Rectangle()
{
	glDeleteBuffers(1, &(this->element_buffer_array));
	glDeleteBuffers(1, &(this->vertex_buffer_object));
	glDeleteVertexArrays(1, &(this->vertex_array_object));
}

void Rectangle::Draw()
{
	glBindVertexArray(this->vertex_array_object);
	glDrawElements(GL_TRIANGLES, this->m_index.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
