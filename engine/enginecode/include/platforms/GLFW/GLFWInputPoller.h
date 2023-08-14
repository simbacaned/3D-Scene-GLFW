/*****************************************************************//**
@file   GLFWInputPoller.h
@brief  Directly checking for the preceding information

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace Engine {
	class GLFWInputPoller
	{
	public:
		static bool isKeyPressed(int32_t keycode);
		static bool isMouseButtonPressed(int32_t button);
		static glm::vec2 getMousePosition();
		static void setCurrentWindow(GLFWwindow* newWin) { s_window = newWin; }
		inline static float getMouseX() { return getMousePosition().x; }
		inline static float getMouseY() { return getMousePosition().y; }
	private:
		static GLFWwindow* s_window;
	};
}
