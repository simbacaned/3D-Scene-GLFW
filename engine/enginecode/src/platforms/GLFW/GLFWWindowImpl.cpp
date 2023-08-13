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

		glfwSetWindowFocusCallback(m_native,
			[](GLFWwindow* window, int state)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
				if (state == GLFW_TRUE) //Gained Focus
				{
					auto& onFocus = handler->getOnFocusCallback();
					WindowFocusEvent e;
					onFocus(e);
				}
				else if (state == GLFW_FALSE) //Lost Focus
				{
					auto& onLostFocus = handler->getOnLostFocusCallback();
					WindowLostFocusEvent e;
					onLostFocus(e);
				}
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

		glfwSetMouseButtonCallback(m_native,
			[](GLFWwindow* window, int button, int action, int mods)
			{
				EventHandler* handler = (EventHandler*)glfwGetWindowUserPointer(window);

				if (action == GLFW_PRESS)
				{
					auto& onButtonPress = handler->getOnMouseButtonPressedCallback();
					MouseButtonPressedEvent e(button);
					onButtonPress(e);
				}
				else if (action == GLFW_RELEASE)
				{
					auto& onButtonRelease = handler->getOnMouseButtonReleasedCallback();
					MouseButtonReleaseEvent e(button);
					onButtonRelease(e);
				}
			}
		);

		glfwSetCursorPosCallback(m_native,
			[](GLFWwindow* window, double newXPos, double newYPos)
			{
				EventHandler* handler = (EventHandler*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e(static_cast<float>(newXPos), static_cast<float>(newYPos));
				auto& onMouseMoved = handler->getOnMouseMovedCallback();
				onMouseMoved(e);
			}
		);

		glfwSetScrollCallback(m_native,
			[](GLFWwindow* window, double newXOffset, double newYOffset)
			{
				EventHandler* handler = (EventHandler*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e(static_cast<float>(newXOffset), static_cast<float>(newYOffset));
				auto& onScrolled = handler->getOnMouseScrollCallback();
				onScrolled(e);
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
