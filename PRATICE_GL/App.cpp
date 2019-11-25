#include <iostream>
#include "Display.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Texture2D.h"
#include <glm/gtx/transform.hpp>
#include "OrbitCamera.h"

#include <array>

Display display(1000, 800, "GL ENGINE", true);
OrbitCamera orbitCamera(glm::vec3(0, 0, 20), glm::vec3(.0f, 0.0f, .0f), 90.0f, 90.f);
ShaderProgram shader("basic_vertex.vert", "basic_fragment.frag");


//display callback function
void DisplayCursorPosCallback(GLFWwindow * window, double offset_x, double offset_y);
void MouseWheelScrollCallback(GLFWwindow * window, double offset_x, double offset_y);

std::array <glm::mat4, 4> modelArray = {
		glm::translate(glm::mat4(1.0f), glm::vec3(-2.5, 0, 0)) * glm::scale(glm::vec3(1.5f)),
		glm::translate(glm::mat4(1.0f), glm::vec3(4, 1.5, 0)) * glm::scale(glm::vec3(1.5f)),
		glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)) * glm::scale(glm::vec3(5.f)),
		glm::translate(glm::mat4(1.0f), glm::vec3(-8, 1.5, 0)) * glm::scale(glm::vec3(1.5f))
};

glm::mat4 projection = glm::perspective(
	glm::radians(90.0f), 
	static_cast<float>(display.GetWidth() / display.GetHeight()), 
	1.0f, 100.0f
);

glm::mat4 view = orbitCamera.ToMatrix();


std::array<Mesh, 4> meshs;
std::array<Texture2D, 4> textures;

std::array<const char *, 4> meshFile;
std::array<const char *, 4> textureFile;

int main(int argc, char** argv)
{
	glfwSetCursorPosCallback(const_cast<GLFWwindow *>(display.GetCurrentWindow()), DisplayCursorPosCallback);
	glfwSetScrollCallback(const_cast<GLFWwindow *>(display.GetCurrentWindow()), MouseWheelScrollCallback);

	meshFile[0] = "3DObject/robot.obj";
	meshFile[1] = "3DObject/woodcrate.obj";
	meshFile[2] = "3DObject/floor.obj";
	meshFile[3] = "3DObject/crate.obj";

	textureFile[0] = "Material/robot_diffuse.jpg";
	textureFile[1] = "Material/woodcrate_diffuse.jpg";
	textureFile[2] = "Material/tile_floor.jpg";
	textureFile[3] = "Material/crate.jpg";


	for (int x = 0; x < meshs.size(); ++x)
	{
		meshs[x].LoadOBJFile(meshFile[x]);
		textures[x].Load(textureFile[x]);
	}


	while (!display.IsClosed())
	{
		display.ClearColor(.3f, .5f, .6f, 1.0f);
		display.EnableDepthTesting();
	
		shader.UseProgram();
	
		view = orbitCamera.ToMatrix();
		shader.SetUniform("projection", projection);
		shader.SetUniform("view", view);

		for (int x = 0; x < meshs.size(); ++x)
		{
			textures[x].Bind();
			shader.SetUniform("model", modelArray[x]);

			meshs[x].Draw();
			textures[x].Unbind();
		}

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

void MouseWheelScrollCallback(GLFWwindow * window, double offset_x, double offset_y)
{
	auto radius = orbitCamera.Get_Radius();
	radius += offset_y * display.GetElapsedTime();
	orbitCamera.Set_Radius(radius);
	orbitCamera.UpdateVectors();
}
