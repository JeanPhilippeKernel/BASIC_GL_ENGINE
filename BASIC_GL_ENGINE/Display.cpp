#include "Display.h"


Display::Display()
	:m_title("GL ENGINE"), m_height(0), m_width(0), m_window(NULL)
{
	INITIALIZE_WINDOW_HINT();

	GLFWmonitor * current_monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* video_mode = glfwGetVideoMode(current_monitor);

	this->m_window = glfwCreateWindow(
		video_mode->width,
		video_mode->height,
		this->m_title.c_str(),
		current_monitor,
		NULL
	);

	if (!this->m_window)
	{
		std::cerr << "Something went wrong while creating window....." << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->m_window);
	glViewport(0, 0, this->m_width, this->m_height);
	glfwSetFramebufferSizeCallback(this->m_window, OnFramebufferSizeChanged);

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Something went wrong while initialize glew library, unable to pursue creating's process of window..." << std::endl;
		exit(EXIT_FAILURE);
	}

	glewExperimental = true;

}


Display::Display(const char* window_title, size_t width, size_t height)
	:m_width(width), m_height(height), m_title(window_title), m_window(NULL)
{
	this->INITIALIZE_WINDOW_HINT();
	this->INITIALIZE_WINDOW();
}

Display::~Display()
{
	glfwDestroyWindow(this->m_window);
	glfwTerminate();
}


bool Display::IsClosed()
{
	int result = glfwWindowShouldClose(this->m_window);
	if (result == GLFW_NOT_INITIALIZED || result == GLFW_PLATFORM_ERROR)
	{
		std::cerr << "GLFW library isn't initialized..." << std::endl;
		exit(EXIT_FAILURE);
	}
	return result;
}

void Display::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(this->m_window);
}

void Display::ClearColor(float r, float g, float b, float a)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(r, g, b, a);
}

void Display::INITIALIZE_WINDOW_HINT()
{
	if (glfwInit() != GLFW_TRUE)
	{
		std::cerr << "Something went wrong while initialize glfw library, unable to create window.." << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


void Display::INITIALIZE_WINDOW()
{
	this->m_window = glfwCreateWindow(
		this->m_width, this->m_height, this->m_title.c_str(),
		NULL, NULL
	);

	if (!this->m_window)
	{
		std::cerr << "Something went wrong while creating window....." << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->m_window);
	glViewport(0, 0, this->m_width, this->m_height);
	glfwSetFramebufferSizeCallback(this->m_window, OnFramebufferSizeChanged);

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Something went wrong while initialize glew library, unable to pursue creating's process of window..." << std::endl;
		exit(EXIT_FAILURE);
	}

	glewExperimental = true;
}

inline void OnFramebufferSizeChanged(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
