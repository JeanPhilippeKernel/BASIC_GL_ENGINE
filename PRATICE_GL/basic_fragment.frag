#version 330 core

in vec3 outputColor;
in vec2 outputTextureCoord;


uniform sampler2D diffuse;

void main()
{
	gl_FragColor = texture2D(diffuse, outputTextureCoord);
}