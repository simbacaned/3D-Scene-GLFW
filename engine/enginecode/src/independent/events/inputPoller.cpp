#include "engine_pch.h"
#ifdef NG_PLATFORM_WINDOWS 
#include "platforms/GLFW/GLFWInputPoller.h"
#endif

namespace Engine {
	class InputPoller
	{
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
	};
}