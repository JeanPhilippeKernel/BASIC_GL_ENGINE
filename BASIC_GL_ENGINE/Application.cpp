#include <iostream>

#include "Display.h"
#include "Shader.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Texture2D.h"
#include "FreeCamera.h"

inline void MouseInputCallback(GLFWwindow* window, double, double);


int main(int argc, char* argv[])
{
	Display display("GL ENGINE", 1000, 800);
	glfwSetCursorPosCallback(display.GetCurrentWindow(), MouseInputCallback);


	
	Shader shader("shader\\basic.vert", "shader\\basic.frag");
	Texture2D texture("assets\\dcube.png");
	Texture2D texture_two("assets\\cubeTexture.jpg");

	/*std::vector<Vertex> vertices{
			Vertex(glm::vec3(0.0f, 0.5f, 0.0), glm::vec3(1.0f, 0.5f, 0.0f)),
			Vertex(glm::vec3(0.5f, -0.5f, 0.0), glm::vec3(1.0f, 0.5f, 0.0f)),
			Vertex(glm::vec3(-0.5f, -0.5f, 0.0), glm::vec3(1.0f, 0.5f, 0.0f)),
	};*/


	/*std::vector<Vertex> vertices{
			Vertex(Vector3f(0.0f, 0.5f, 0.0), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(0.5f, -0.5f, 0.0), Vector3f(.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, 0.0), Vector3f(.0f, 0.0f, 1.0f), Vector2f(0.0f, 0.0f)),
	};

	Triangle mesh(vertices);*/


	/*std::vector<Vertex> vertices_2{
			Vertex(Vector3f(0.5f, 0.5f, 0.0f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(0.5f, -0.5f, 0.0f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, 0.0f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, 0.5f, 0.0f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
	};

	Rectangle rectangle_mesh(vertices_2);*/

	

	std::vector<Vertex> vertices_3{
			Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(0.5f, -0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(0.5f,  0.5f, -0.5f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(0.5f,  0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(-0.5f,  0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),



			Vertex(Vector3f(-0.5f, -0.5f,  0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(0.5f, -0.5f,  0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(0.5f,  0.5f,  0.5f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(0.5f,  0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(-0.5f,  0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(-0.5f, -0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),



			Vertex(Vector3f(-0.5f,  0.5f,  0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(-0.5f,  0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(-0.5f, -0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-0.5f,  0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),


			Vertex(Vector3f(0.5f,  0.5f,  0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(0.5f,  0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(0.5f, -0.5f, -0.5f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(0.5f, -0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(0.5f, -0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(0.5f,  0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
		
	
			Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(0.5f, -0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(0.5f, -0.5f,  0.5f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(0.5f, -0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, -0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),


			Vertex(Vector3f(-0.5f,  0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(0.5f,  0.5f, -0.5f), Vector3f(.0f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),
			Vertex(Vector3f(0.5f,  0.5f,  0.5f), Vector3f(.0f, 0.0f, 1.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(0.5f,  0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(-0.5f,  0.5f,  0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-0.5f,  0.5f, -0.5f), Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f))
	};

	Cube cube_mesh(vertices_3);


	//model-view-projection matrix
	glm::mat4 model_matrix, view_matrix, perspective_matrix;
														  //
	model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f)) * glm::rotate(glm::mat4(1.0f), glm::quarter_pi<float>(), glm::vec3(1.0f, 0.0f, 0.0f));
	

	FreeCamera freeCamera(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); 
	view_matrix = freeCamera.GetViewMatrix();

	
	perspective_matrix = glm::perspective(glm::radians(45.0f), (display.GetWidth() / display.GetHeight()), 0.1f, 100.0f);


	while (!display.IsClosed())
	{
		display.ClearColor(0.1f, 0.5f, 0.6f, 1.0f);
		display.EnableDepth();
		display.ClearDepth();

		shader.Use();
		texture.Bind();
		texture_two.Bind(1);

		//model_matrix = glm::rotate(glm::mat4(1.0f), glm::radians((float)glfwGetTime() * 50.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		shader.SetUniform("model_matrix", model_matrix);
		shader.SetUniform("view_matrix", view_matrix);
		shader.SetUniform("perspective_matrix", perspective_matrix);

		shader.SetUniform("diffuse", 0);
		shader.SetUniform("diffuse_two", 1);
																	 
		cube_mesh.Draw();

		display.Update();
	}


	return 0;
}

inline void MouseInputCallback(GLFWwindow* window, double cursor_pos_x, double cursor_pos_y)
{
	std::cout << "pos X : " << cursor_pos_x
		<< " " << "pos Y : " << cursor_pos_y
		<< std::endl;
}
