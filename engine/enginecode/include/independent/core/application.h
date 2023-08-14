/*****************************************************************//**
@file   application.h
@brief  The Application class is responsible for managing the main application loop, handling events, and coordinating various system components.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "systems/log.h"
#include "timer.h"
#include "events/events.h"
#include "events/eventHandler.h"
#include "core/window.h"
#include "cameras/cameraControllerEuler.h"

namespace Engine {
	/**
	* @class Application
	* @brief Represents the main application class.
	*/
	class Application
	{
	protected:
		/** @brief Protected constructor for the Application class.*/
		Application();
		std::shared_ptr<Log> m_logSystem; /**< Shared pointer to the log system. */
		std::shared_ptr<Timer> m_timer;   /**< Shared pointer to the timer. */
		std::shared_ptr<System> m_windowsSystem; /**< Shared pointer to the window system. */
		std::shared_ptr<Window> m_window; /**< Shared pointer to the main application window. */
		//std::shared_ptr<CameraControllerEuler> m_camera; /**< Shared pointer to the camera. */
	private:
		static Application* s_instance; /**< Static pointer to the application instance. */
		bool m_running = true; /**< Flag indicating whether the application is running. */

		// Event handling methods
		bool onFocus(WindowFocusEvent& e);
		bool onLostFocus(WindowLostFocusEvent& e);
		bool onClose(WindowCloseEvent& e);
		bool onResize(WindowResizeEvent& e);
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);
		bool onMouseButtonPressed(MouseButtonPressedEvent& e);
		bool onMouseButtonReleased(MouseButtonReleaseEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		bool onMouseScroll(MouseScrolledEvent& e);
	public:
		/** @brief Virtual destructor for the Application class.*/
		virtual ~Application();

		/**
		* @brief Get the singleton instance of the Application class.
		* @return Reference to the singleton instance of the Application class.
		*/
		inline static Application& getInstance() { return *s_instance; }
		/** @brief Run the application.*/
		void run();
	};
	/**
	* @brief Start the application and return a pointer to the instance.
	* @return Pointer to the Application instance.
	*/
	Application* startApplication(); 
}