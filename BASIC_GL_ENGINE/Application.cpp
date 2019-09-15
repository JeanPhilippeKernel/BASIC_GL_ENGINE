#include <iostream>

#include "Display.h"
#include "Shader.h"
#include "Triangle.h"

int main(int argc, char* argv[])
{
	Display display("GL ENGINE", 1000, 800);
	//Display display;
	
	Shader shader("shader\\basic.vert", "shader\\basic.frag");

	/*std::vector<Vertex> vertices{
			Vertex(glm::vec3(0.0f, 0.5f, 0.0), glm::vec3(1.0f, 0.5f, 0.0f)),
			Vertex(glm::vec3(0.5f, -0.5f, 0.0), glm::vec3(1.0f, 0.5f, 0.0f)),
			Vertex(glm::vec3(-0.5f, -0.5f, 0.0), glm::vec3(1.0f, 0.5f, 0.0f)),
	};*/


	std::vector<Vertex> vertices{
			Vertex(Vector3f(0.0f, 0.5f, 0.0), Vector3f(1.0f, 0.0f, 0.0f)),
			Vertex(Vector3f(0.5f, -0.5f, 0.0), Vector3f(.0f, 1.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, 0.0), Vector3f(.0f, 0.0f, 1.0f)),
	};

	Triangle mesh(vertices);

	while (!display.IsClosed())
	{
		display.ClearColor(0.1f, 0.5f, 0.6f, 1.0f);

		shader.Use();

		auto variation = glm::vec3(std::sin(glfwGetTime()), std::cos(glfwGetTime()), 1);
		auto offset = glm::vec3(std::sin(glfwGetTime()) / 2, std::cos(glfwGetTime()) / 2, 1);
		
		shader.SetUniform("variable_color", variation);
		shader.SetUniform("position_offset", offset);
																	 
		mesh.Draw();

		display.Update();
	}


	return 0;
}