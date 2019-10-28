#pragma once
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>



class Texture2D
{
public:
	Texture2D(std::string filename);
	~Texture2D();

	void Bind(int textureUnit = 0);
	void UnBind(int textureUnit = 0);
	
private:
	GLuint m_texture_handle;
	std::string m_filename;

};

