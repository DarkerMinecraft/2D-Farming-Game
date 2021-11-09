#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class DisplayManager
{
public:
	static bool createDisplay(int, int, const char*);
	static void updateDisplay();
	static void destroyDisplay();
	static bool isDisplayRunning();
private:
	inline static GLFWwindow* m_Window;
};