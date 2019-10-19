#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>



Texture2D::Texture2D(std::string filename)
	:m_texture_handle(0), m_filename(filename)
{
	stbi_set_flip_vertically_on_load(true);

	int image_width, image_height, image_component;
	unsigned char* image_data = stbi_load(m_filename.c_str(), &image_width, &image_height, &image_component, STBI_rgb_alpha);

	if (image_data == NULL)
	{
		std::cerr << "error while loading image file..." << std::endl;
		exit(EXIT_FAILURE);
	}

	glGenTextures(1, &(this->m_texture_handle));
	glBindTexture(GL_TEXTURE_2D, this->m_texture_handle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)image_data);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(image_data);
}


void Texture2D::Bind(int textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, this->m_texture_handle);
	
}

void Texture2D::UnBind(int textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &(this->m_texture_handle));
}