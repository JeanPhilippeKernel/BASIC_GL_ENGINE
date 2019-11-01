#pragma once
#include <string>
#include <fstream>
#include <iostream>	
#include <sstream>

#include <GL/glew.h>
#include <glm/glm.hpp>

class ShaderProgram
{
public:
	explicit ShaderProgram(const char * vertexFilename, const char * fragmentFilename);
	~ShaderProgram();

	void UseProgram();

	GLuint GetProgram() const;


	void SetUniform(const char* location, int value);
	void SetUniform(const char* location, float value);
	
	void SetUniform(const char* location, glm::vec2 value);
	void SetUniform(const char* location, glm::vec3 value);
	void SetUniform(const char* location, glm::vec4 value);
	
	void SetUniform(const char* location, glm::mat2 value);
	void SetUniform(const char* location, glm::mat3 value);
	void SetUniform(const char* location, glm::mat4 value);



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

