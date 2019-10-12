#include <iostream>

#include "Display.h"
#include "Shader.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Texture2D.h"

#include "FreeCamera.h"
#include "OrbitCamera.h"


OrbitCamera orbitCamera(glm::vec3(0, 0, 0), 20.f, 55.f, 60.f);

static glm::vec2 lastMousePos = glm::vec2(0.0f, 0.0f);

const float MOUSE_SENSITIVITY = 0.25f;


inline void MouseInputCallback(GLFWwindow* window, double, double);
inline void MouseInputScrollCallback(GLFWwindow* window, double, double);


int main(int argc, char* argv[])
{
	Display display("GL ENGINE", 1000, 800);
	glfwSetCursorPosCallback(display.GetCurrentWindow(), MouseInputCallback);
	glfwSetScrollCallback(display.GetCurrentWindow(), MouseInputScrollCallback);

	
	Shader shader("shader/basic.vert", "shader/basic.frag");
	Texture2D texture("assets/dcube.png");
	Texture2D texture_two("assets/cubeTexture.jpg");
	Texture2D texture_three("assets/floor.jpg");

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

	

	std::vector<Vertex> vertices_3 {
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
	Cube floor(vertices_3);


	//model-view-projection matrix
	glm::mat4 model_matrix, view_matrix, perspective_matrix;
														
	model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model_matrix_two = glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 0.01f, 10.f)) * glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -60.0f, 0.0f));
	

	view_matrix = orbitCamera.GetViewMatrix();
	perspective_matrix = glm::perspective(glm::radians(45.0f), (display.GetWidth() / display.GetHeight()), 0.1f, 100.0f);


	while (!display.IsClosed())
	{
		display.ClearColor(0.1f, 0.5f, 0.6f, 1.0f);
		display.EnableDepth();
		display.ClearDepth();

		shader.Use();
		texture.Bind();
		texture_two.Bind(1);

		view_matrix = orbitCamera.GetViewMatrix();

		shader.SetUniform("model_matrix", model_matrix);
		shader.SetUniform("view_matrix", view_matrix);
		shader.SetUniform("perspective_matrix", perspective_matrix);

		shader.SetUniform("diffuse", 0);
		shader.SetUniform("diffuse_two", 1);
																	 
		cube_mesh.Draw();


		texture_three.Bind();
		texture_three.Bind(1);
		shader.SetUniform("model_matrix", model_matrix_two);
		floor.Draw();


		display.Update();
	}


	return 0;
}

inline void MouseInputCallback(GLFWwindow* window, double cursor_pos_x, double cursor_pos_y)
{
	float current_yaw = glm::degrees(orbitCamera.GetYawAngle());
	float current_pitch = glm::degrees(orbitCamera.GetPitchAngle());

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		current_yaw -= (static_cast<float>(cursor_pos_x) - lastMousePos.x) * MOUSE_SENSITIVITY;
		current_pitch += (static_cast<float>(cursor_pos_y) - lastMousePos.y) * MOUSE_SENSITIVITY;
	}

	lastMousePos.x = static_cast<float>(cursor_pos_x);
	lastMousePos.y = static_cast<float>(cursor_pos_y);

	orbitCamera.SetPitchAngle(current_pitch);
	orbitCamera.SetYawAngle(current_yaw);
	orbitCamera.UpdatePosition();
}

inline void MouseInputScrollCallback(GLFWwindow* window, double x, double y)
{
	auto radius = orbitCamera.GetRadius(); 
	radius += y * MOUSE_SENSITIVITY;

	orbitCamera.SetRadius(radius);
	orbitCamera.UpdatePosition();
}
