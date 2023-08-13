/*****************************************************************//**
@file   window.h
@brief  The Window class defines an abstract interface for managing application windows, providing methods for initialization, rendering, event handling, and more.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include "events/eventHandler.h"
#include "core/graphicsContext.h"

namespace Engine
{
	/**
	* @struct WindowProperties
	* @brief Structure containing properties for window creation.
	* The WindowProperties structure encapsulates the properties required for creating a window, such as title, dimensions, fullscreen mode, and vsync settings.
	*/
	struct WindowProperties
	{
		char* title;         /**< The title of the window. */
		uint32_t width;      /**< The width of the window. */
		uint32_t height;     /**< The height of the window. */
		bool isFullScreen;   /**< Flag indicating whether the window should be in fullscreen mode. */
		bool isVSync;        /**< Flag indicating whether vertical synchronization (vsync) is enabled. */

		/**
		* @brief Constructor for WindowProperties.
		* @param title The title of the window.
		* @param width The width of the window.
		* @param height The height of the window.
		* @param fullscreen Flag indicating whether the window should be in fullscreen mode.
		*/
		WindowProperties(char* title = "My Window", uint32_t width = 800, uint32_t height = 600, bool fullscreen = false)
			: title(title), width(width), height(height), isFullScreen(fullscreen) {}
	};
    /**
    * @class Window
    * @brief Abstract base class for window interfaces.
    */
    class Window
    {
    public:
        /**
         * @brief Initialize the window with specified properties.
         * @param properties Properties for window creation.
         */
        virtual void init(const WindowProperties& properties) = 0;

        /** @brief Close and clean up the window.*/
        virtual void close() = 0;

        /** @brief Virtual destructor for Window class.*/
        virtual ~Window() {};

        /**
        * @brief Update the window with a specified time step.
        * @param timestep The time step for the update.
        */
        virtual void onUpdate(float timestep) = 0;

        /**
        * @brief Set vertical synchronization (vsync) state for the window.
        * @param VSync Flag indicating whether vsync should be enabled.
        */
        virtual void setVSync(bool VSync) = 0;

        /**
        * @brief Get the width of the window.
        * @return The width of the window.
        */
        virtual unsigned int getWidth() const = 0;

        /**
        * @brief Get the height of the window.
        * @return The height of the window.
        */
        virtual unsigned int getHeight() const = 0;

        /**
        * @brief Get a pointer to the native window object.
        * @return Pointer to the native window object.
        */
        virtual void* getNativeWindow() const = 0;

        /**
        * @brief Check if the window is in fullscreen mode.
        * @return True if the window is in fullscreen mode, false otherwise.
        */
        virtual bool isFullScreenMode() const = 0;

        /**
        * @brief Check if vertical synchronization (vsync) is enabled for the window.
        * @return True if vsync is enabled, false otherwise.
        */
        virtual bool isVSync() const = 0;

        /**
        * @brief Get the event handler associated with the window.
        * @return Reference to the event handler.
        */
        inline EventHandler& getEventHandler() { return m_eventHandler; }

        /**
        * @brief Create a window with the specified properties.
        * @param properties Properties for window creation.
        * @return Pointer to the created window instance.
        */
        static Window* create(const WindowProperties& properties = WindowProperties());

	protected:
        EventHandler m_eventHandler; /**< The event handler for the window. */
        std::shared_ptr<GraphicsContext> m_graphicsContext; /**< Shared pointer to the graphics context. */
	};
}