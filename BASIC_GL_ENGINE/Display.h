#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Display
{
public:
	Display();
	Display(const char * window_title, size_t width, size_t height);
	virtual  ~Display();


	bool IsClosed();

	void Update();
	void ClearColor(float r, float g, float b, float a);

	void EnableDepth();
	void ClearDepth();

	float GetHeight() const;
	float GetWidth() const;

	GLFWwindow* GetCurrentWindow() const;

	float GetElapsedTime() const;


private:
	GLFWwindow* m_window;
	std::string m_title;
	size_t m_height, m_width;


	double previousSecond = 0.0;
	double currentSecond = glfwGetTime();
	double elapsedSecond = 0.0f;


	void INITIALIZE_WINDOW_HINT();
	void INITIALIZE_WINDOW();

	void FramePerSecondCounter();
};

inline void OnFramebufferSizeChanged(GLFWwindow* window, int width, int height);


