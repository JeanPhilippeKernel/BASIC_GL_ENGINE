#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#include "Vector3f.h"
#include "Vertex.h"

class ObjParser
{
public:
	explicit ObjParser(const char * filename);
	~ObjParser();

	const std::vector<Vertex>& ToVertices() const;


private:
	std::vector<Vector3f> m_positions;
	std::vector<Vector3f> m_textures;
	std::vector<Vector3f> m_normals;

	std::vector<Vertex> m_vertices;
};

