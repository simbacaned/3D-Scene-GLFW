/** \file application.cpp
*/

#include "engine_pch.h"
#include "systems/log.h";
#include "platforms\GLFW\GLFWWindowImpl.h"
#include "platforms\GLFW\GLFW_OpenGL_GC.h"

namespace Engine
{
#ifdef NG_PLATFORM_WINDOWS
	Window* Window::create(const WindowProperties& properties)
	{
		return new GLFWWindowImpl(properties);
	}
#endif

	GLFWWindowImpl::GLFWWindowImpl(const WindowProperties& properties)
	{
		init(properties);

	}

	void GLFWWindowImpl::init(const WindowProperties& properties)
	{
		m_props = properties;
		m_aspectRatio = static_cast<float>(m_props.width) / static_cast<float>(m_props.height);

		if (m_props.isFullScreen)
		{
			Log::error("fullscreen not yet implemented");
		}
		else
		{
			m_native = glfwCreateWindow(m_props.width, m_props.height, m_props.title, nullptr, nullptr);
		}

		m_graphicsContext.reset(new GLFW_OpenGL_GC(m_native));
		m_graphicsContext->init();

		glfwSetWindowUserPointer(m_native, &m_eventHandler);

		glfwSetWindowCloseCallback(m_native,
			[](GLFWwindow* window)
			{
				auto handler = (EventHandler*)glfwGetWindowUserPointer(window);
				auto callback = handler->getOnCloseCallback();

				WindowCloseEvent wc;
				callback(wc);
			}
		);

		glfwSetWindowSizeCallback(m_native,
			[](GLFWwindow* window, int newWidth, int newHeight)
			{
				auto handler = (EventHandler*)glfwGetWindowUserPointer(window);
				auto callback = handler->getOnResizeCallback();

				WindowResizeEvent wc(newWidth, newHeight);
				callback(wc);
			}
		);

		glfwSetKeyCallback(m_native,
			[](GLFWwindow* window, int keyCode, int scanCode, int action, int mods)
			{
				auto handler = (EventHandler*)glfwGetWindowUserPointer(window);

				if (action == GLFW_PRESS)
				{
					auto& callback = handler->getOnKeyPressedCallback();

					KeyPressedEvent wc(keyCode, 0);
					callback(wc);
				}

				else if (action == GLFW_REPEAT)
				{
					auto& callback = handler->getOnKeyPressedCallback();

					KeyPressedEvent wc(keyCode, 1);
					callback(wc);
				}

				else if (action == GLFW_RELEASE)
				{
					auto& callback = handler->getOnKeyReleasedCallback();

					KeyReleasedEvent wc(keyCode);
					callback(wc);
				}
			}
		);	


	}
	void GLFWWindowImpl::close()
	{
		glfwDestroyWindow(m_native);
	}
	void GLFWWindowImpl::onUpdate(float timestep)
	{
		glfwPollEvents();
		m_graphicsContext->swapBuffers();
	}
	void GLFWWindowImpl::setVSync(bool VSync)
	{
		m_props.isVSync = VSync;
		if (m_props.isVSync) { glfwSwapInterval(1); }
		else { glfwSwapInterval(0); }
	}
}
