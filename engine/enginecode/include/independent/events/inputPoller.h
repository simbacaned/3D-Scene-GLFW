/*****************************************************************//**
@file   inputPoller.h
@brief  Directly checking for the preceding information

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <glm/glm.hpp>

namespace Engine {
	class InputPoller
	{
	public:
		static bool isKeyPressed(int keycode);
		static bool isMouseButtonPressed(int button);
		static glm::vec2 getMousePosition();
		static void setCurrentWindow(void* newWin);
		inline static float getMouseX() { return getMousePosition().x; }
		inline static float getMouseY() { return getMousePosition().y; }
	};
}
