#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;


uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 perspective_matrix;


out vec3 outColor;

void main()
{

	//vec4 pos_in_clip_space =  
	//gl_Position =   model_matrix * vec4(position, 1.0);
	gl_Position =  perspective_matrix * view_matrix * model_matrix * vec4(position, 1.0);
	
	//gl_Position =  vec4(position, 1.0);
	
	outColor = color;
}