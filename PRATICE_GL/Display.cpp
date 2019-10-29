#include "Display.h"



Display::Display()
	:m_width(800), m_height(600), m_title("GL ENGINE")
{
	INITIALIZE_WINDOW();
}


Display::Display(int width, int height, std::string title)
	:m_width(width), m_height(height), m_title(title)
{
	INITIALIZE_WINDOW();
}

Display::~Display()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

bool Display::IsClosed() const
{
	int flag = glfwWindowShouldClose(m_window);
	if (flag == GLFW_NOT_INITIALIZED)
	{					   
		std::cerr << "unable to get close flag, glfw initialized error" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	return flag;
}

void Display::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}


void Display::INITIALIZE_WINDOW_HINT()
{

	int glfw_init = glfwInit();
	if (glfw_init != GLFW_TRUE)
	{
		std::cerr << "unable to initialize GLFW LIBRARY....." << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

void Display::INITIALIZE_WINDOW()
{
	INITIALIZE_WINDOW_HINT();

	m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title.c_str(), NULL, NULL);
	if (m_window == NULL)
	{
		std::cerr << "unable to create window ...." << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(m_window);
	glViewport(0, 0, m_width, m_height);
	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow * window, int width, int height) { glViewport(0, 0, width, height); });

	int gl_init = glewInit();
	if (gl_init != GLEW_OK)
	{
		std::cerr << "unable to initialize GL  ...." << std::endl;
		exit(EXIT_FAILURE);
	}

	glewExperimental = true;

}

void Display::PROCESSING_FPS()
{
}