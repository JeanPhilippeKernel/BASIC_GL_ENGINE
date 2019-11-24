#include "Display.h"


float Display::m_elapsedTime = 0;
double Display::m_lastTime = 0;
int Display::m_frameCount = 0;


Display::Display()
	:m_width(800), m_height(600), m_title("GL ENGINE"), m_isVSyncEnabled(false)
{
	INITIALIZE_WINDOW();
}


Display::Display(int width, int height, std::string title, bool vsync)
	:m_width(width), m_height(height), m_title(title), m_isVSyncEnabled(vsync)
{
	INITIALIZE_WINDOW();
}

Display::~Display()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}


void Display::SetTitle(const std::string& title)
{
	if (!title.empty())
		m_title = title;

	UPDATE_WINDOW_PROPERTIES();
}

void Display::SetHeight(int height)
{
	if (height < 600) return;
	m_height = height;
	UPDATE_WINDOW_PROPERTIES();
}

void Display::EnableVSync(bool vsync)
{
	if (vsync)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_isVSyncEnabled = vsync;
}

void Display::SetWidth(int width)
{
	if (width < 800) return;
	m_width = width;

	UPDATE_WINDOW_PROPERTIES();
}


bool Display::IsClosed() const
{
	int flag = glfwWindowShouldClose(m_window);
	if (flag == GLFW_NOT_INITIALIZED || flag == GLFW_PLATFORM_ERROR)
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
	
	PROCESSING_FPS();
}


void Display::ClearColor(float r, float g, float b, float a)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(r, g, b, a);
}

void Display::EnableDepthTesting()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
}


void Display::INITIALIZE_WINDOW_HINT()
{
	glfwSetErrorCallback([](int errorCode, const char* description) { std::cerr << "Error Code : " << errorCode << "\nDescription : " << description;   });


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
	glfwSwapInterval(static_cast<int>(m_isVSyncEnabled));
	glViewport(0, 0, m_width, m_height);
	
	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });


	int gl_init = glewInit();
	if (gl_init != GLEW_OK)
	{
		std::cerr << "unable to initialize Graphic Layer...." << std::endl;
		exit(EXIT_FAILURE);
	}

	glewExperimental = true;

}

void Display::PROCESSING_FPS()
{
	float currentTime = static_cast<float>(glfwGetTime());

	m_elapsedTime = currentTime - static_cast<float>(m_lastTime);
	if (m_elapsedTime >= 1.0f)
	{
		m_lastTime = currentTime;
		float msPerFrame = 1000.0f / m_frameCount;

		std::stringstream ss;
		ss.precision(3);
		ss << std::fixed << "FPS : " << m_frameCount << " Frame time : " << msPerFrame << "(ms)";
		this->SetTitle(ss.str());

		m_frameCount = 0;
	}
	m_frameCount++;

}

void Display::UPDATE_WINDOW_PROPERTIES()
{
	glfwSetWindowTitle(m_window, m_title.c_str());
	glfwSetWindowSize(m_window, m_width, m_height);
}
