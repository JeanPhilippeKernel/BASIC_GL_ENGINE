#pragma once
#include "Mesh.h"


class Rectangle : public Mesh
{
public:
	Rectangle(std::vector<Vertex>& const vertices);
	~Rectangle();


	void Draw() override;

};

