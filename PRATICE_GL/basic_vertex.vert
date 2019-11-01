#version 330 core 

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 textureCoord;


out vec3 outputColor;
out vec3 outputTextureCoord;


void main()
{
	gl_Position = vec4(position, 1.0f);
	outputColor = color;
	outputTextureCoord = textureCoord;
}