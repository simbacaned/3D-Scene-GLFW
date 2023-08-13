/*****************************************************************//**
@file   event.h
@brief  Foundation for event handling. Introduces event types, categories, and a base class to manage and differentiate events.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include <intTypes.h>

namespace Engine 
{
	/**
	* @enum EventType
	* @brief Enumerates types of events.
	*
	* The EventType enum class defines various types of events that can occur in the application.
	*/
	enum class EventType
	{
		None = 0,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			KeyPressed, KeyReleased, KeyType, MouseButtonPressed, MouseButtonReleased,
			MouseMoved, MouseScrolled
	};
	/**
	* @enum EventCategory
	* @brief Enumerates categories of events.
	*
	* The EventCategory enum defines different categories of events, helping to classify them.
	*/
	enum EventCategory
	{
		None = 0,
		EventCategoryWindow = 1 << 0,
		EventCategoryInput = 1 << 1,
		EventCategoryKeyboard = 1 << 2,
		EventCategoryMouse = 1 << 3,
		EventCategoryMouseButton = 1 << 4
	};

	/**
	* @class Event
	* @brief Base class for event objects.
	*/
	class Event
	{
	public:
		/**
		* @brief Get the type of the event.
		* @return The type of the event.
		*/
		virtual EventType getEventType() const = 0;

		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags of the event.
		*/
		virtual int32_t getCategoryFlags() const = 0;

		/**
		* @brief Check if the event has been handled.
		* @return True if the event has been handled, false otherwise.
		*/
		inline bool handled() const { return m_handled; }

		/**
		* @brief Set the handled state of the event.
		* @param isHandled Flag indicating whether the event is handled.
		*/
		inline void handle(bool isHandled) { m_handled = isHandled; }

		/**
		* @brief Check if the event belongs to a specific category.
		* @param category The category to check.
		* @return True if the event is in the specified category, false otherwise.
		*/
		inline bool isInCategory(EventCategory category) const { return getCategoryFlags() & category; }

	protected:
		bool m_handled = false; /**< Flag indicating whether the event is handled. */
	};
}
