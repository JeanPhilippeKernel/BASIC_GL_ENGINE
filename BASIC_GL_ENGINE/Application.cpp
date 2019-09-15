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
			Vertex(Vector3f(0.0f, 0.5f, 0.0), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(0.5f, -0.5f, 0.0), Vector3f(.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, 0.0), Vector3f(.0f, 0.0f, 1.0f), Vector2f(0.0f, 0.0f)),
	};

	Triangle mesh(vertices);


	//model-view-projection matrix
	glm::mat4 model_matrix, view_matrix, perspective_matrix;

	model_matrix =  glm::rotate(glm::mat4(1.0f), glm::radians(-70.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
	
	perspective_matrix = glm::perspective(glm::radians(45.0f), (display.GetWidth() / display.GetHeight()), 0.1f, 100.0f);


	while (!display.IsClosed())
	{
		display.ClearColor(0.1f, 0.5f, 0.6f, 1.0f);

		shader.Use();

		shader.SetUniform("model_matrix", model_matrix);
		shader.SetUniform("view_matrix", view_matrix);
		shader.SetUniform("perspective_matrix", perspective_matrix);
																	 
		mesh.Draw();

		display.Update();
	}


	return 0;
}