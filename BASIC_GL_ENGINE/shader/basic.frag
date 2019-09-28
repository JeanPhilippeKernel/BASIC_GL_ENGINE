#version 330 core


in vec3 outColor;
in vec2 outTexCoord;


uniform sampler2D diffuse;
uniform sampler2D diffuse_two;

out vec4 outputColor;

void main()
{
	 outputColor =   mix(
		texture2D(diffuse, outTexCoord), 
		texture2D(diffuse_two, outTexCoord), 
		0.5f
	 ); /*vec4(outColor, 1.0f);  */
}