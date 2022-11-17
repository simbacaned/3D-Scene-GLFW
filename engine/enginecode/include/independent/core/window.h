/** \file timer.h
*/
#pragma once
#include "events/eventHandler.h"
#include "core/graphicsContext.h"

namespace Engine
{
	struct WindowProperties
	{
		char* title;
		uint32_t width;
		uint32_t height;
		bool isFullScreen;
		bool isVSync;

		WindowProperties(char* title = "My Window", uint32_t width = 800, uint32_t height = 600, bool fullscreen = false) : title(title), width(width), height(height), isFullScreen(fullscreen) {}
	};
	class Window
	{
	public:
		virtual void init(const WindowProperties& properties) = 0;
		virtual void close() = 0;
		virtual ~Window() {};
		virtual void onUpdate(float timestep) = 0;
		virtual void setVSync(bool VSync) = 0;
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;
		virtual void* getNativeWindow() const = 0;
		virtual bool isFullScreenMode() const = 0;
		virtual bool isVSync() const = 0;

		inline EventHandler& getEventHandler() { return m_eventHandler; }

		static Window* create(const WindowProperties& properties = WindowProperties());
	protected:
		EventHandler m_eventHandler;
		std::shared_ptr<GraphicsContext> m_graphicsContext;
	};
}