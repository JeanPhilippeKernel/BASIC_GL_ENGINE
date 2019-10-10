#pragma once
#include <iostream>
#include <string>

#include <GL/glew.h>

constexpr auto BUFFER_SIZE = 2048;

namespace common 
{
	inline bool check_shader_compiling_status(const GLuint& shader_handle)
	{
		GLint status;
		GLint info_log_length;
		GLint shader_type;

		glGetShaderiv(shader_handle, GL_COMPILE_STATUS, &status);
		glGetShaderiv(shader_handle, GL_INFO_LOG_LENGTH, &info_log_length);
		glGetShaderiv(shader_handle, GL_SHADER_TYPE, &shader_type);
		
		if (glIsProgram(shader_handle) == GL_TRUE)
		{
			std::cerr << "this shader type isn't supported for checking..." << std::endl;
			exit(EXIT_FAILURE);
		}

		if (status == GL_FALSE)
		{
			GLchar log_info[BUFFER_SIZE];
			glGetShaderInfoLog(shader_handle, BUFFER_SIZE, &info_log_length, log_info);
			
			std::cerr << log_info << std::endl;
		}
		else
		{
			const char* shader_name = (shader_type == GL_VERTEX_SHADER) ? "vertex_shader" : "fragment";
			std::cout << shader_name << " : " << " compiled successfully..." << std::endl;
		}

		return status;
	}


	inline bool check_shader_linking_status(const GLuint& program_handle)
	{
		GLint status;
		GLint info_log_length;


		glGetProgramiv(program_handle, GL_LINK_STATUS, &status);
		glGetProgramiv(program_handle, GL_INFO_LOG_LENGTH, &info_log_length);

		if (glIsShader(program_handle) == GL_TRUE)
		{
			std::cerr << "this shader type isn't supported for linking checking..." << std::endl;
			exit(EXIT_FAILURE);
		}

		if (status == GL_FALSE)
		{
			GLchar log_info[BUFFER_SIZE];
			glGetProgramInfoLog(program_handle, BUFFER_SIZE, &info_log_length, log_info);
			std::cerr << log_info << std::endl;
		}

		else
		{
			std::cout << "program_shader : " << " compiled successfully..." << std::endl;
		}


		return status;
	}

	inline bool check_shader_validating_status(const GLuint& program_handle)
	{
		GLint status;
		GLint info_log_length;


		glGetProgramiv(program_handle, GL_VALIDATE_STATUS, &status);
		glGetProgramiv(program_handle, GL_INFO_LOG_LENGTH, &info_log_length);

		if (glIsShader(program_handle) == GL_TRUE)
		{
			std::cerr << "this shader type isn't supported for linking checking..." << std::endl;
			exit(EXIT_FAILURE);
		}

		if (status == GL_FALSE)
		{
			GLchar log_info[BUFFER_SIZE];
			glGetProgramInfoLog(program_handle, BUFFER_SIZE, &info_log_length, log_info);
			std::cerr << log_info << std::endl;
		}

		else
		{
			std::cout << "program_shader : " << " validated successfully..." << std::endl;
		}


		return status;
	}

}


