#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include <iostream>
					
class Display
{
public:
	explicit Display(int width, int height, std::string title);
	~Display();

	bool IsClosed() const;
	void Update();


	int GetHeight() const { return m_height; }
	int GetWidth() const { return m_width; }
	const std::string& GetTitle() const { return m_title; }
	GLFWwindow const * GetCurrentWindow() const { return m_window; }


	void SetTitle(const std::string& title) 
	{
		if (!title.empty())
			m_title = title;
		
	}

	void SetHeight(int height)
	{
		if (height < 600) return;
		m_height = height;
	}

	void SetWidth(int width) 
	{
		if (width < 800) return;
		m_width = width;
	}


private:
	Display();

	int m_height, m_width;
	std::string m_title;
	double m_elpasedTime;

	GLFWwindow * m_window;


	void INITIALIZE_WINDOW_HINT();
	void INITIALIZE_WINDOW();

	void PROCESSING_FPS();
};

