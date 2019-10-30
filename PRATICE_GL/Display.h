#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include <iostream>
#include <sstream>
#include <functional>
					
class Display
{
public:
	explicit Display(int width, int height, std::string title, bool vsync = false);
	~Display();

	bool IsClosed() const;
	void Update();


	int GetHeight() const { return m_height; }
	int GetWidth() const { return m_width; }
	const std::string& GetTitle() const { return m_title; }
	double GetElapsedTime() const { return m_elapsedTime; }
	bool IsVSyncEnabledr() const { return m_isVSyncEnabled; }

	GLFWwindow const * GetCurrentWindow() const { return m_window; }


	void SetTitle(const std::string& title);
	void SetWidth(int width);
	void SetHeight(int height);

	void EnableVSync(bool vsync);


	void ClearColor(float r, float g, float b, float a);
	void EnableDepthTesting();

private:
	Display();

	int m_height, m_width;
	std::string m_title;

	static double m_lastTime;
	static float m_elapsedTime;
	static int m_frameCount;

	bool m_isVSyncEnabled;

	GLFWwindow * m_window;


	void INITIALIZE_WINDOW_HINT();
	void INITIALIZE_WINDOW();

	void PROCESSING_FPS();

	void UPDATE_WINDOW_PROPERTIES();
};

