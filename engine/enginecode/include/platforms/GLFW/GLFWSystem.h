/** \file entryPoint.h
*/
#pragma once
#include "systems/system.h"
#include "systems/log.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Engine
{
	void errorCallback(
		GLenum source,
		GLenum type,
		GLenum id,
		GLenum severity,
		GLenum length,
		const GLchar* message,
		const void* userParam)
	{

	}
		
		class GLFWSystem : public System
	{
		virtual void start(SystemSignal init = SystemSignal::None, ...) override
		{
			auto errorCode = glfwInit();
			if (!errorCode)
			{
				Log::error("Cannot init GLFW: {0}", errorCode);
			}
		}
		virtual void stop(SystemSignal close = SystemSignal::None, ...) override
		{
			glfwTerminate();
		}
	};
}