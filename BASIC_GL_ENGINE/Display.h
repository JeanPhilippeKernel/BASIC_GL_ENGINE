#pragma once
#include <iostream>
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

	float GetHeight() const;
	float GetWidth() const;

private:
	GLFWwindow* m_window;
	std::string m_title;
	size_t m_height, m_width;



	void INITIALIZE_WINDOW_HINT();
	void INITIALIZE_WINDOW();
};

inline void OnFramebufferSizeChanged(GLFWwindow* window, int width, int height);


