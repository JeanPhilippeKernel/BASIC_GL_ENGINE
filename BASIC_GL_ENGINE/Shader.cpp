#include "Shader.h"


using namespace common;

Shader::Shader(const char* vertex_filename, const char* fragment_filename)
{
	std::ifstream vertex_input_stream, fragment_input_stream;
	std::stringstream vertex_string_buffer, fragment_string_buffer;

	vertex_input_stream.exceptions(std::ios::failbit | std::ios::badbit);
	fragment_input_stream.exceptions(std::ios::failbit | std::ios::badbit);

	try
	{
		vertex_input_stream.open(vertex_filename, std::ios::_Noreplace | std::ios::_Nocreate);
		fragment_input_stream.open(fragment_filename, std::ios::_Noreplace | std::ios::_Nocreate);
														 

		std::filebuf* vertex_stream_buffer = vertex_input_stream.rdbuf();
		std::filebuf* fragment_stream_buffer = fragment_input_stream.rdbuf();

		vertex_string_buffer << vertex_stream_buffer;
		fragment_string_buffer << fragment_stream_buffer;

		vertex_input_stream.close();
		fragment_input_stream.close();

		this->vertex_shader_source = vertex_string_buffer.str();
		this->fragment_shader_source = fragment_string_buffer.str();

		vertex_string_buffer.clear();
		fragment_string_buffer.clear();


		CHECKING_SHADER_COMPILATION(COMPILE_SHADER());
		CHECKING_SHADER_LINKING(LINKING_SHADER());
		CHECKING_SHADER_VALIDATION(VALIDATING_SHADER());

		glDeleteShader(this->vertex_shader_handle);
		glDeleteShader(this->fragment_shader_handle);

	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

}

Shader::~Shader()
{
	glDeleteProgram(this->program_shader_handle);
}

void Shader::Use()
{
	glUseProgram(this->program_shader_handle);
}

void Shader::SetUniform(const char* uniform_name, int value)
{
	GLint location = this->GetUniform(uniform_name);
	if(location != -1)
		glUniform1i(location, value);
}

void Shader::SetUniform(const char* uniform_name, float value)
{
	GLint location = this->GetUniform(uniform_name);
	if (location != -1)
		glUniform1f(location, value);
}

void Shader::SetUniform(const char* uniform_name, glm::vec2& const value)
{
	GLint location = this->GetUniform(uniform_name);
	if (location != -1)
		glUniform2f(location, value.x, value.y);
}

void Shader::SetUniform(const char* uniform_name, glm::vec3& const value)
{
	GLint location = this->GetUniform(uniform_name);
	if (location != -1)
		glUniform3f(location, value.x, value.y, value.z);
}

void Shader::SetUniform(const char* uniform_name, glm::vec4& const value)
{
	GLint location = this->GetUniform(uniform_name);
	if (location != -1)
		glUniform4f(location, value.x, value.y, value.z, value.w);
}


void Shader::SetUniform(const char* uniform_name, glm::mat4& const value)
{
	GLint location = this->GetUniform(uniform_name);
	if(location != -1)
		glUniformMatrix4fv(location, 1, false, glm::value_ptr(value));
}

GLint Shader::GetUniform(const char* uniform_name)
{
	std::string name(uniform_name);
	std::map<std::string, GLint>::iterator it = this->m_uniform_location.find(name);
	
	if (it == this->m_uniform_location.end())
	{
		GLint index = glGetUniformLocation(this->program_shader_handle, uniform_name);
		if (index != -1)
			this->m_uniform_location[name] = glGetUniformLocation(this->program_shader_handle, uniform_name);
		return index;
	}
	else
		return it->second;
}

bool Shader::COMPILE_SHADER()
{
	this->vertex_shader_handle = glCreateShader(GL_VERTEX_SHADER);
	this->fragment_shader_handle = glCreateShader(GL_FRAGMENT_SHADER);


	const GLchar* vs_source = this->vertex_shader_source.c_str();
	const GLchar* fs_source = this->fragment_shader_source.c_str();

	const GLint vs_lenght = std::strlen(vs_source);
	const GLint fs_lenght = std::strlen(fs_source);

	
	glShaderSource(this->vertex_shader_handle, 1, &vs_source, &vs_lenght);
	glShaderSource(this->fragment_shader_handle, 1, &fs_source, &fs_lenght);

	glCompileShader(this->vertex_shader_handle);
	auto  vertex_compile_state = check_shader_compiling_status(this->vertex_shader_handle);


	glCompileShader(this->fragment_shader_handle);
	auto  fragment_compile_state = check_shader_compiling_status(this->fragment_shader_handle);

	return vertex_compile_state && fragment_compile_state;
}

bool Shader::LINKING_SHADER()
{
	this->program_shader_handle = glCreateProgram();
	glAttachShader(this->program_shader_handle, this->vertex_shader_handle);
	glAttachShader(this->program_shader_handle, this->fragment_shader_handle);

	glLinkProgram(this->program_shader_handle);
	
	
	return check_shader_linking_status(this->program_shader_handle);
}

bool Shader::VALIDATING_SHADER()
{
	glValidateProgram(this->program_shader_handle);
	return check_shader_validating_status(this->program_shader_handle);
}
