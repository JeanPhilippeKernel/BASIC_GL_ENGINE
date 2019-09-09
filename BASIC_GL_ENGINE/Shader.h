#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <map>

#include <GLEW/glew.h>
#include <GLM/glm.hpp>

#include "Common.h"

#define CHECKING_SHADER_LINKING(X) \
	if ((X) == false) { std::cerr << "shader linking failed..." << std::endl; exit(EXIT_FAILURE); }	\
	

#define CHECKING_SHADER_COMPILATION(X) \
	if((X) == false) { std::cerr << "shader compilation failed..." << std::endl; exit(EXIT_FAILURE); }	\
	


#define CHECKING_SHADER_VALIDATION(X) \
	if((X) == false) { std::cerr << "shader validation failed..." << std::endl; exit(EXIT_FAILURE); }	\
	


class Shader
{
public:
	Shader(const char * vertex_filename, const char * fragment_filename);
	virtual ~Shader();

	void Use();

	void SetUniform(const char* uniform_name, int value);
	void SetUniform(const char* uniform_name, float value);

	void SetUniform(const char* uniform_name, glm::vec2& const value);
	void SetUniform(const char* uniform_name, glm::vec3& const  value);
	void SetUniform(const char* uniform_name, glm::vec4& const value);

private:
	GLuint vertex_shader_handle;
	GLuint fragment_shader_handle;
	GLuint program_shader_handle;

	std::string vertex_shader_source;
	std::string fragment_shader_source;


	std::map<std::string, GLuint> m_uniform_location;


	GLuint GetUniform(const char* uniform_name);

	bool COMPILE_SHADER();
	bool LINKING_SHADER();
	bool VALIDATING_SHADER();

};

