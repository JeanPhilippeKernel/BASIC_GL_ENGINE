#pragma once
#include "Mesh.h"
#include <array>


class Rectangle : public Mesh
{
public:
	Rectangle(std::vector<Vertex>& const vertices);
	virtual ~Rectangle();


	void Draw() override;

private:
	std::array<unsigned int, 6> m_index;

};

