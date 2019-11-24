#version 330 core

in vec3 outputColor;
in vec2 outputTextureCoord;


out vec4 frag_color;

uniform sampler2D diffuse;
//uniform sampler2D diffuse_two;
//uniform sampler2D diffuse_three;

void main()
{



//	frag_color = mix(
//	mix(texture2D(diffuse, outputTextureCoord), texture2D(diffuse_two, outputTextureCoord), 0.0f),
//	texture2D(diffuse_three, outputTextureCoord), 
//	.0f);


	frag_color = texture2D(diffuse, outputTextureCoord);


}