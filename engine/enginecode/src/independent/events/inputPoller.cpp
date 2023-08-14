#include "engine_pch.h"
#ifdef NG_PLATFORM_WINDOWS 
#include "platforms/GLFW/GLFWInputPoller.h"
#include "events/inputPoller.h"
#endif

namespace Engine {
	bool InputPoller::isKeyPressed(int keycode)
	{
		return GLFWInputPoller::isKeyPressed(keycode);
	}

	bool InputPoller::isMouseButtonPressed(int button)
	{
		return GLFWInputPoller::isMouseButtonPressed(button);
	}

	glm::vec2 InputPoller::getMousePosition()
	{
		return GLFWInputPoller::getMousePosition();
	}

	void InputPoller::setCurrentWindow(void* newWin)
	{
		GLFWInputPoller::setCurrentWindow((GLFWwindow*)newWin);
	}
}