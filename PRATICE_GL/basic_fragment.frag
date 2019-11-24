#version 330 core

in vec3 outputColor;
in vec2 outputTextureCoord;


out vec4 frag_color;

uniform sampler2D diffuse;

void main()
{

	frag_color = texture2D(diffuse, outputTextureCoord);
}