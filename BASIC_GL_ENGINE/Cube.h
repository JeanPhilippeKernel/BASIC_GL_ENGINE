#pragma once
#include "Mesh.h"


class Cube : public Mesh
{
public:
	Cube(std::vector<Vertex>& const vertices);
	virtual ~Cube();


	virtual void Draw() override; 

};