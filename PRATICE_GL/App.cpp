#include <iostream>
#include "Display.h"
#include "ShaderProgram.h"
#include "Mesh.h"


Display display(1000, 800, "GL ENGINE", true);
ShaderProgram shader("basic_vertex.vert", "basic_fragment.frag");

Mesh mesh(std::vector<Vertex> {
	Vertex(),

});


int main(int argc, char** argv)
{

	while (!display.IsClosed())
	{
		display.ClearColor(.2f, .5f, .3f, 1.0f);
		display.EnableDepthTesting();

		shader.UseProgram();
		mesh.Draw();

		display.Update();
	}	  

	return 0;
}