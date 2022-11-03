/** \file application.cpp
*/
#include <iostream>
#include "engine_pch.h"
#include "core/application.h"

#ifdef NG_PLATFORM_WINDOWS
	#include "platforms/windows/winTimer.h"
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
#else
		m_timer.reset(new ChronoTimer);
#endif
		m_timer->start();

		m_handler.setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));

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
	}


	void Application::run()
	{
		float timestep = 0.0f;
		float accumTime = 0.0f;
		while (m_running)
		{
			timestep = m_timer->getTimeElapsed();
			m_timer->reset();
			//Log::trace("FPS {0}", 1.0f / timestep);
			accumTime += timestep;
			//Log::trace("Cumalative time {0}", accumTime);
			if (accumTime > 2.0f)
			{
				
				WindowCloseEvent close;
				
				auto& callback = m_handler.getOnCloseCallback();
				callback(close);
			}
		};
	}

}
