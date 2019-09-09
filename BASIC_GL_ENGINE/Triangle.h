#pragma once
#include "Mesh.h"


class Triangle : public Mesh
{

public:
	Triangle(std::vector<Vertex>& const vertices);
	virtual ~Triangle();

	 void Draw() override;
};

