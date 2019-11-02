#include <iostream>
#include "Display.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include <glm/gtx/transform.hpp>


Display display(1000, 800, "GL ENGINE", false);

ShaderProgram shader("basic_vertex.vert", "basic_fragment.frag");

//Mesh mesh(
//	"Material/box.png",
//	std::vector<Vertex> {
//		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
//
//		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
//
//		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(.0f, 0.0f, 1.0f),	Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
//		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
//
//		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(.0f, 0.0f, 1.0f),	Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
//
//		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, -0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, 0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
//		Vertex(Vector3f(-0.5f, -0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
//
//		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(.0f, 1.0f, 0.0f),	Vector2f(0.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, -0.5f),		Vector3f(.0f, 1.0f, 0.0f),	Vector2f(1.0f, 1.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(.0f, 0.0f, 1.0f),	Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
//		Vertex(Vector3f(-0.5f, 0.5f, 0.5f),		Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
//		Vertex(Vector3f(-0.5f, 0.5f, -0.5f),	Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f))
//});
//

Mesh robot("3DObject/robot.obj");

glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(display.GetWidth() / display.GetHeight()), 1.0f, 100.0f);
glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -20));


int main(int argc, char** argv)
{

	shader.UseProgram();
	

	while (!display.IsClosed())
	{
		display.ClearColor(.2f, .5f, .3f, .5f);
		display.EnableDepthTesting();

		shader.SetUniform("model", model);
		shader.SetUniform("projection", projection);
		shader.SetUniform("view", view);


		robot.Draw();

		display.Update();
	}	  

	return 0;
}