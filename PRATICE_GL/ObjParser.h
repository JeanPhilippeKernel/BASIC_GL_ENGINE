#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Vector3f.h"

class ObjParser
{
public:
	ObjParser();
	~ObjParser();


private:
	std::vector<Vector3f> m_positions;
	std::vector<Vector3f> m_textures;
	std::vector<Vector3f> m_normals;
};

