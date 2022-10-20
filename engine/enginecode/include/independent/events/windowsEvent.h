/** \file system.h
*/
#pragma once
#include "event.h"

#include <glm/glm.hpp>

/**
\class Interface class for all systems
*/

namespace Engine 
{

	class WindowCloseEvent : public Event
	{
		static EventType getStaticType() { return EventType::WindowClose; }
		virtual inline EventType getEventType() const override { return EventType::WindowClose; }
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int32_t width, int32_t height) : m_width(width), m_height(height) {}
		static EventType getStaticType() { return EventType::WindowResize; }
		virtual inline EventType getEventType() const override { return EventType::WindowResize; }
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	private:
		int32_t m_width;
		int32_t m_height;
	};
}
