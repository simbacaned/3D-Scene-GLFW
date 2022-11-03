/** \file application.cpp
*/
#include <iostream>
#include "engine_pch.h"
#include "core/application.h"

#ifdef NG_PLATFORM_WINDOWS
	#include "platforms/windows/winTimer.h"
	#include "platforms/GLFW/GLFWSystem.h"
#endif


namespace Engine {
	// Set static vars
	Application* Application::s_instance = nullptr;

	Application::Application()
	{
		if (s_instance == nullptr)
		{
			s_instance = this;
		}
		//start systems

		//start log
		m_logSystem.reset(new Log);
		m_logSystem->start();

		//reset timer
#ifdef NG_PLATFORM_WINDOWS
		m_timer.reset(new WinTimer);
		m_windowsSystem.reset(new GLFWSystem);
#else
		m_timer.reset(new ChronoTimer);
#endif
		m_timer->start();

		m_windowsSystem->start();

		WindowProperties props("My Game Engine", 1024, 800);

		m_window.reset(Window::create(props));

		m_window->getEventHandler().setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));

		m_timer->reset();
	}

	bool Application::onClose(WindowCloseEvent& e)
	{
		m_running = false;

		return true;

		return e.handled();
	}

	Application::~Application()
	{
		//stop systems

		//stop log
		m_logSystem->stop();

		m_windowsSystem->stop();
	}


	void Application::run()
	{
		float timestep = 0.0f;

		while (m_running)
		{
			timestep = m_timer->getTimeElapsed();
			m_timer->reset();
			//Log::trace("FPS {0}", 1.0f / timestep);
	
			//Log::trace("Cumalative time {0}", accumTime);
			
			m_window->onUpdate(timestep);
		};
	}

}
