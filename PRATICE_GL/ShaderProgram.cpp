#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char * vertexFilename, const char * fragmentFilename)
	
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

		vertex_stream.close();
		fragment_stream.close();
	}
	catch (const std::ios::failure& e)
	{
		std::cerr << e.what() << std::endl;
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

GLint ShaderProgram::GetUniformLocation(const char * uniform_name)
{
	GLint output;
	auto find = m_location_container.find(uniform_name);
	if (find == m_location_container.end())
	{
		output = glGetUniformLocation(m_program_handler, uniform_name);
		if (output != -1)
			m_location_container[uniform_name] = output;
	}
	else
		output = find->second;

	return output;
}


void ShaderProgram::SetUniform(const char * location, int value)
{
	auto  l = GetUniformLocation(location);
	glUniform1i(l, value);
}

void ShaderProgram::SetUniform(const char * location, float value)
{
	auto  l = GetUniformLocation(location);
	glUniform1f(l, value);
}

void ShaderProgram::SetUniform(const char * location, glm::vec2 value)
{
	auto  l = GetUniformLocation(location);
	glUniform2f(l, value.x, value.y);
}

void ShaderProgram::SetUniform(const char * location, glm::vec3 value)
{
	auto  l = GetUniformLocation(location);
	glUniform3f(l, value.x, value.y, value.z);
}

void ShaderProgram::SetUniform(const char * location, glm::vec4 value)
{
	auto  l = GetUniformLocation(location);
	glUniform4f(l, value.x, value.y, value.z, value.w);
}

void ShaderProgram::SetUniform(const char * location, glm::mat2 value)
{
	auto  l = GetUniformLocation(location);
	glUniformMatrix2fv(l, 1, GL_FALSE,  glm::value_ptr(value));
}

void ShaderProgram::SetUniform(const char * location, glm::mat3 value)
{
	auto  l = GetUniformLocation(location);
	glUniformMatrix3fv(l, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::SetUniform(const char * location, glm::mat4 value)
{
	auto  l = GetUniformLocation(location);
	glUniformMatrix4fv(l, 1, GL_FALSE, glm::value_ptr(value));
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
