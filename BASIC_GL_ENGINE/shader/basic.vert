#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;


uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 perspective_matrix;


out vec3 outColor;
out vec2 outTexCoord;

void main()
{

	gl_Position =  perspective_matrix * view_matrix * model_matrix * vec4(position, 1.0);

	outTexCoord = texCoord;
	outColor = color;
}