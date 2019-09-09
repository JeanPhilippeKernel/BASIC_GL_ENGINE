#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& const vertices)
	:vertex_array_object(0), vertex_buffer_object(0), m_vertices(vertices)
{

	std::for_each(m_vertices.begin(), m_vertices.end(),
		[this](const Vertex& vertex) 
		{  
			m_raw_vertices.push_back(vertex.GetPosition().x); 
			m_raw_vertices.push_back(vertex.GetPosition().y); 
			m_raw_vertices.push_back(vertex.GetPosition().z); 
			
			m_raw_vertices.push_back(vertex.GetColor().x); 
			m_raw_vertices.push_back(vertex.GetColor().y);
			m_raw_vertices.push_back(vertex.GetColor().z);
		});
}

Mesh::~Mesh()
{
}

GLsizei Mesh::VerticeByteSize() const
{
	return sizeof(float) * m_raw_vertices.size();
}
