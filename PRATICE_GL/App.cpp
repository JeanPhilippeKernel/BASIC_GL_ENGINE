#include <iostream>
#include "Display.h"
#include "ShaderProgram.h"
#include "Mesh.h"


Display display(1000, 800, "GL ENGINE", true);

ShaderProgram shader("basic_vertex.vert", "basic_fragment.frag");

Mesh mesh(
	"Material/box.png",
	std::vector<Vertex> {
		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 0.0f)),
		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),

		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 0.0f)),
		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),

		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(.0f, 0.0f, 1.0f),	Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),

		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(.0f, 0.0f, 1.0f),	Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),

		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),

		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 1.0f)),
		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f))
});


int main(int argc, char** argv)
{

	shader.UseProgram();

	while (!display.IsClosed())
	{
		display.ClearColor(.2f, .5f, .3f, .5f);
		display.EnableDepthTesting();

		mesh.Draw();

		display.Update();
	}	  

	return 0;
}