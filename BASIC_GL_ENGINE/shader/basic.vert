#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;



uniform vec3 variable_color;
uniform vec3 position_offset;


uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 perspective_matrix;


out vec3 outColor;

void main()
{

	vec4 pos_in_clip_space =  perspective_matrix * view_matrix * model_matrix * vec4(position, 1.0);
	gl_Position =  pos_in_clip_space;
	
	outColor = variable_color *0.5f;
}