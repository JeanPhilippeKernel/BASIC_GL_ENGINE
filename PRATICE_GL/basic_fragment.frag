#version 330 core

in vec3 outputColor;

void main()
{
	gl_FragColor = vec4(outputColor, 1.0f);
}