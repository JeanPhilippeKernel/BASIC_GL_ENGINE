#include <iostream>

#include "Display.h"
#include "Shader.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Texture2D.h"

#include "FreeCamera.h"
#include "OrbitCamera.h"
#include "FPSCamera.h"


//OrbitCamera orbitCamera(glm::vec3(3, 5, 2), glm::vec3(0, 0, 0), 55.f, 60.f);
FPSCamera fpsCamera(glm::vec3(0, 0, 5), glm::vec3(0, 0, 0), glm::pi<float>(), 0);
//model-view-projection matrix
glm::mat4 model_matrix, view_matrix, perspective_matrix;

static glm::vec2 lastMousePos = glm::vec2(0.0f, 0.0f);

const float MOUSE_SENSITIVITY = 0.1f;
const float MOVE_SPEED = 5.0;
															 
inline void Update(float deltaTime);

inline void MouseInputCallback(GLFWwindow* window, double, double);
inline void MouseInputScrollCallback(GLFWwindow* window, double, double);
inline void KeyInputCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

Display display("GL ENGINE", 1000, 800);


int main(int argc, char* argv[])
{
	glfwSetInputMode(display.GetCurrentWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(display.GetCurrentWindow(), display.GetWidth() / 2.0, display.GetHeight() / 2.0);

	//glfwSetCursorPosCallback(display.GetCurrentWindow(), MouseInputCallback);
	glfwSetScrollCallback(display.GetCurrentWindow(), MouseInputScrollCallback);
	glfwSetKeyCallback(display.GetCurrentWindow(), KeyInputCallback);
	
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


	
														
	model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model_matrix_two = glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 0.01f, 10.f)) * glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -60.0f, 0.0f));
	

	view_matrix = fpsCamera.GetViewMatrix();
	perspective_matrix = glm::perspective(glm::radians(fpsCamera.GetFov()), (display.GetWidth() / display.GetHeight()), 0.1f, 100.0f);


	float lastime = 0.0f;
	float currentTime;


	while (!display.IsClosed())
	{
		display.ClearColor(0.1f, 0.5f, 0.6f, 1.0f);
		display.EnableDepth();
		display.ClearDepth();

		currentTime = (float)glfwGetTime();

		shader.Use();
		texture.Bind();
		texture_two.Bind(1);

		view_matrix = fpsCamera.GetViewMatrix();

		shader.SetUniform("model_matrix", model_matrix);
		shader.SetUniform("view_matrix", view_matrix);
		shader.SetUniform("perspective_matrix", perspective_matrix);

		shader.SetUniform("diffuse", 0);
		shader.SetUniform("diffuse_two", 1);
																	 
		cube_mesh.Draw();

		texture.UnBind();
		texture.UnBind(1);


		texture_three.Bind();
		texture_three.Bind(1);
		shader.SetUniform("model_matrix", model_matrix_two);
		floor.Draw();

		texture.UnBind();
		texture.UnBind(1);

		float deltaTime = currentTime - lastime;
		Update(deltaTime);

		lastime = currentTime;

		display.Update();
	}


	return 0;
}

inline void Update(float deltaTime)
{
	double mouseX, mouseY;

	// Get the current mouse cursor position delta
	glfwGetCursorPos(display.GetCurrentWindow(), &mouseX, &mouseY);

	// Rotate the camera the difference in mouse distance from the center screen.  Multiply this delta by a speed scaler
	fpsCamera.Rotate((float)(display.GetWidth() / 2.0 - mouseX) * MOUSE_SENSITIVITY, (float)(display.GetHeight() / 2.0 - mouseY) * MOUSE_SENSITIVITY);

	// Clamp mouse cursor to center of screen
	glfwSetCursorPos(display.GetCurrentWindow(), display.GetWidth() / 2.0, display.GetHeight() / 2.0);


	// Forward/backward
	if (glfwGetKey(display.GetCurrentWindow(), GLFW_KEY_W) == GLFW_PRESS)
		fpsCamera.Move(MOVE_SPEED *deltaTime *  fpsCamera.GetForward());
	else if (glfwGetKey(display.GetCurrentWindow(), GLFW_KEY_S) == GLFW_PRESS)
		fpsCamera.Move(MOVE_SPEED *  deltaTime* -fpsCamera.GetForward());

	// Strafe left/right
	if (glfwGetKey(display.GetCurrentWindow(), GLFW_KEY_A) == GLFW_PRESS)
		fpsCamera.Move(MOVE_SPEED *deltaTime *   -fpsCamera.GetRigth());
	else if (glfwGetKey(display.GetCurrentWindow(), GLFW_KEY_D) == GLFW_PRESS)
		fpsCamera.Move(MOVE_SPEED * deltaTime* fpsCamera.GetRigth());
												    
	// Up/down
	if (glfwGetKey(display.GetCurrentWindow(), GLFW_KEY_Z) == GLFW_PRESS)
		fpsCamera.Move(MOVE_SPEED * deltaTime*  fpsCamera.GetUp());
	else if (glfwGetKey(display.GetCurrentWindow(), GLFW_KEY_X) == GLFW_PRESS)
		fpsCamera.Move(MOVE_SPEED * deltaTime* -fpsCamera.GetUp());
}


inline void MouseInputCallback(GLFWwindow* window, double cursor_pos_x, double cursor_pos_y)
{
	/*float current_yaw = fpsCamera.GetYawAngle();
    float current_pitch = fpsCamera.GetPitchAngle();

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		current_yaw -= (static_cast<float>(cursor_pos_x) - lastMousePos.x) * MOUSE_SENSITIVITY;
		current_pitch += (static_cast<float>(cursor_pos_y) - lastMousePos.y) * MOUSE_SENSITIVITY;
	}

	lastMousePos.x = static_cast<float>(cursor_pos_x);
	lastMousePos.y = static_cast<float>(cursor_pos_y);

	fpsCamera.Rotate(current_yaw, current_pitch);*/
	

}

inline void MouseInputScrollCallback(GLFWwindow* window, double x, double y)
{
	auto radius = fpsCamera.GetRadius(); 
	radius += y * MOUSE_SENSITIVITY;

	fpsCamera.SetRadius(radius);

	float current_yaw = fpsCamera.GetYawAngle();
	float current_pitch = fpsCamera.GetPitchAngle();
	fpsCamera.Rotate(current_yaw, current_pitch);
	
}

inline void KeyInputCallback(GLFWwindow * window, int key, int scanCode, int action, int mods)
{
	
}
