#pragma once

#include <GL/glew.h>
#include <iostream>


class Texture2D
{
public:
	Texture2D();
	~Texture2D();


	void Load(const char * filename);
	void Bind(int texture_unit = 0);
	void Unbind(int texture_unit = 0);

private:
	GLuint m_texture_handler;
};

