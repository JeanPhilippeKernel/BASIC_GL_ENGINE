#pragma once
#include <string>
#include <fstream>
#include <iostream>	
#include <sstream>

#include <GL/glew.h>

class ShaderProgram
{
public:
	explicit ShaderProgram(std::string vertexFilename, std::string fragmentFilename);
	~ShaderProgram();

	void UseProgram();

	GLuint GetProgram() const;


private:
	GLuint m_vertex_shader_handler;
	GLuint m_fragment_shader_handler;

	std::string m_vertex_shader_source;
	std::string m_fragment_shader_source;

	GLuint m_program_handler;

	void Compile();
	void LinkingAndAssemble();
	void Validate();
};

