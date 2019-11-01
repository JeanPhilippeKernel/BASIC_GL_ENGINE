#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexFilename, std::string fragmentFilename)
	
{
	std::fstream vertex_stream, fragment_stream;
	vertex_stream.exceptions(std::fstream::badbit | std::fstream::failbit);

	try
	{
		vertex_stream.open(vertexFilename, std::fstream::in);
		fragment_stream.open(fragmentFilename, std::fstream::in);

		auto vs_buffer = vertex_stream.rdbuf();
		auto fs_buffer = fragment_stream.rdbuf();

		std::stringstream vs_string_stream, fs_string_stream;
		vs_string_stream << vs_buffer;
		fs_string_stream << fs_buffer;

		this->m_vertex_shader_source = vs_string_stream.str();
		this->m_fragment_shader_source = fs_string_stream.str();

		Compile();
		LinkingAndAssemble();
		Validate();


		glDeleteShader(m_vertex_shader_handler);
		glDeleteShader(m_fragment_shader_handler);
	}
	catch (const std::exception&)
	{
		std::cerr << "unable to open shader files..." << std::endl;
	}

}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_program_handler);

}

void ShaderProgram::UseProgram()
{
	if (m_program_handler != 0)
		glUseProgram(m_program_handler);
}

GLuint ShaderProgram::GetProgram() const
{
	return m_program_handler;
}

void ShaderProgram::Compile()
{
	this->m_vertex_shader_handler = glCreateShader(GL_VERTEX_SHADER);
	this->m_fragment_shader_handler = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vs_source = this->m_vertex_shader_source.c_str();
	const char* fs_source = this->m_fragment_shader_source.c_str();

	GLint vs_length = std::strlen(vs_source);
	GLint fs_length = std::strlen(fs_source);

	glShaderSource(m_vertex_shader_handler, 1, &vs_source, &vs_length);
	glShaderSource(m_fragment_shader_handler, 1, &fs_source, &fs_length);

	glCompileShader(m_vertex_shader_handler);
	// info log of compilation...

	glCompileShader(m_fragment_shader_handler);
	// info log of compilation...
}


void ShaderProgram::LinkingAndAssemble()
{
	this->m_program_handler = glCreateProgram();
	glAttachShader(m_program_handler, m_vertex_shader_handler);
	glAttachShader(m_program_handler, m_fragment_shader_handler);

	glLinkProgram(m_program_handler);
	// info log of linking...
}

void ShaderProgram::Validate()
{
	glValidateProgram(m_program_handler); 
	// info log of validate program...
}
