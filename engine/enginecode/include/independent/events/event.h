/** \file system.h
*/
#pragma once
#include <intTypes.h>

/**
\class Interface class for all systems
*/

namespace Engine 
{

	enum class EventType
	{
		None = 0,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			KeyPressed, KeyReleased, KeyType, MouseButtonPressed, MouseButtonReleased,
			MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryWindow = 1 << 0,
		EventCategoryInput = 1 << 1,
		EventCategoryKeyboard = 1 << 2,
		EventCategoryMouse = 1 << 3,
		EventCategoryMouseButton = 1 << 4
	};

	class Event
	{
	public:
		virtual EventType getEventType() const = 0;
		virtual int32_t getCategoryFlags() const = 0;
		inline bool handled() const { return m_handled; }
		inline void handle(bool isHandled) { m_handled = isHandled; }
		inline bool isInCategory(EventCategory category) const { return getCategoryFlags() & category; }
	protected:
		bool m_handled = false;
	};
}
