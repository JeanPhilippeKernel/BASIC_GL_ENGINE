#include <iostream>
#include "Display.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include <glm/gtx/transform.hpp>
#include "OrbitCamera.h"

Display display(1000, 800, "GL ENGINE", false);
OrbitCamera orbitCamera(glm::vec3(0, 0, 20), glm::vec3(.0f, -5.0f, .0f), 55.0f, 80.f);

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

glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -5, 0)) * glm::scale(glm::vec3(1.2f));
glm::mat4 projection = glm::perspective(
	glm::radians(45.0f), 
	static_cast<float>(display.GetWidth() / display.GetHeight()), 
	1.0f, 100.0f
);

glm::mat4 view = orbitCamera.ToMatrix();



//display callback function
void DisplayCursorPosCallback(GLFWwindow * window, double offset_x, double offset_y);

int main(int argc, char** argv)
{

	glfwSetCursorPosCallback(const_cast<GLFWwindow *>(display.GetCurrentWindow()), DisplayCursorPosCallback);

	shader.UseProgram();
	
	while (!display.IsClosed())
	{
		display.ClearColor(.3f, .5f, .6f, 1.0f);
		display.EnableDepthTesting();

		view = orbitCamera.ToMatrix();
		
		shader.SetUniform("model", model);
		shader.SetUniform("projection", projection);
		shader.SetUniform("view", view);


		robot.Draw();

		display.Update();
	}	  

	return 0;
}



void DisplayCursorPosCallback(GLFWwindow * window, double cursor_pos_x, double cursor_pos_y)
{
	static float last_cursor_pos_x  = 0;
	static float last_cursor_pos_y = 0;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		auto delta_x = (float)cursor_pos_x - last_cursor_pos_x;
		auto delta_y = (float)cursor_pos_y - last_cursor_pos_y;


		auto yaw_in_deg = glm::degrees(orbitCamera.Get_Yaw_Angle());
		auto pitch_in_deg = glm::degrees(orbitCamera.Get_Pitch_Angle());

		yaw_in_deg -= delta_x;
		pitch_in_deg += delta_y;

		orbitCamera.Set_Yaw_Angle(yaw_in_deg);
		orbitCamera.Set_Pitch_Angle(pitch_in_deg);

		last_cursor_pos_x = cursor_pos_x;
		last_cursor_pos_y = cursor_pos_y;
		orbitCamera.UpdateVectors();
	}

	


}