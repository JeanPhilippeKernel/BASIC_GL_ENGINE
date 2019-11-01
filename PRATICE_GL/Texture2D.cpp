#include "Texture2D.h"

#include <stb_image.h>

#define STB_IMPLEMENTATION


Texture2D::Texture2D()
{
	glGenTextures(1, &m_texture_handler);
	glBindTexture(GL_TEXTURE_2D, m_texture_handler);
	glBindTexture(GL_TEXTURE_2D, 0);
}


Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_texture_handler);
}

void Texture2D::Load(const char * filename)
{
	glBindTexture(GL_TEXTURE_2D, m_texture_handler);


	stbi_set_flip_vertically_on_load(true);

	int width, height, texture_component;
	stbi_uc * data = stbi_load(filename, &width, &height, &texture_component, STBI_rgb_alpha);
	if (data == NULL)
	{
		std::cerr << "failed to load texture of mesh" << std::endl;
		exit(EXIT_FAILURE);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, reinterpret_cast<void *>(data));
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
}

void Texture2D::Bind(int texture_unit)
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(GL_TEXTURE_2D, m_texture_handler);
}

void Texture2D::Unbind(int texture_unit)
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(GL_TEXTURE_2D, 0);
}
