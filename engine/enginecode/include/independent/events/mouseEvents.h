/*****************************************************************//**
@file   mouseEvents.h
@brief  The MouseEvent class serves as the base class for events related to mouse interactions.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include "event.h"
#include <glm/glm.hpp>
 
namespace Engine 
{
	/**
	* @class MouseEvent
	* @brief Base class for mouse-related events.
	*/
	class MouseEvent : public Event
	{
		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags, including EventCategoryMouse and EventCategoryInput.
		*/
		virtual inline int32_t getCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }
	};

	/**
	* @class MouseMovedEvent
	* @brief Event representing mouse movement.
	*/
	class MouseMovedEvent : public MouseEvent
	{
	public:
		/**
		* @brief Constructor for MouseMovedEvent.
		* @param x The new x-coordinate of the mouse cursor.
		* @param y The new y-coordinate of the mouse cursor.
		*/
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}
		/**
		* @brief Get the static event type of MouseMovedEvent.
		* @return The EventType of MouseMovedEvent.
		*/
		static EventType getStaticType() { return EventType::MouseMoved; }
		/**
		* @brief Get the dynamic event type of MouseMovedEvent.
		* @return The EventType of the event.
		*/
		virtual EventType getEventType() const override { return getStaticType(); }
		/**
		* @brief Get the x-coordinate of the mouse cursor.
		* @return The x-coordinate of the mouse cursor.
		*/
		inline float getX() const { return m_mouseX; }
		/**
		* @brief Get the y-coordinate of the mouse cursor.
		* @return The y-coordinate of the mouse cursor.
		*/
		inline float getY() const { return m_mouseY; }
		/**
		* @brief Get the position of the mouse cursor as a glm::vec2.
		* @return The position of the mouse cursor.
		*/
		inline glm::vec2 getPos() const { return glm::vec2(m_mouseX, m_mouseY); } 

	private:
		float m_mouseX, m_mouseY; /**< The new coordinates of the mouse cursor. */
	};

	/**
	* @class MouseScrolledEvent
	* @brief Event representing mouse scrolling.
	* The MouseScrolledEvent class represents an event where the mouse wheel is scrolled.
	*/
	class MouseScrolledEvent : public MouseEvent
	{
	public:
		/**
		* @brief Constructor for MouseScrolledEvent.
		* @param xOffset The amount of horizontal scrolling.
		* @param yOffset The amount of vertical scrolling.
		*/
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		/**
		* @brief Get the static event type of MouseScrolledEvent.
		* @return The EventType of MouseScrolledEvent.
		*/
		static EventType getStaticType() { return EventType::MouseScrolled; }

		/**
		* @brief Get the dynamic event type of MouseScrolledEvent.
		* @return The EventType of the event.
		*/
		virtual EventType getEventType() const override { return getStaticType(); }

		/**
		* @brief Get the amount of horizontal scrolling.
		* @return The amount of horizontal scrolling.
		*/
		inline float getXOffset() const { return m_xOffset; }

		/**
		* @brief Get the amount of vertical scrolling.
		* @return The amount of vertical scrolling.
		*/
		inline float getYOffset() const { return m_yOffset; }
	private:
		float m_xOffset, m_yOffset; /**< The amounts of horizontal and vertical scrolling. */
	};

	/**
	* @class MouseButtonPressedEvent
	* @brief Event representing a mouse button being pressed.
	* The MouseButtonPressedEvent class represents an event where a mouse button is pressed.
	* It provides information about the button that was pressed.
	*/
	class MouseButtonPressedEvent : public MouseEvent
	{
	public:
		/**
		* @brief Constructor for MouseButtonPressedEvent.
		* @param button The ID of the pressed mouse button.
		*/
		MouseButtonPressedEvent(int32_t button) : m_button(button) {}
		/**
		* @brief Get the static event type of MouseButtonPressedEvent.
		* @return The EventType of MouseButtonPressedEvent.
		*/
		static EventType getStaticType() { return EventType::MouseButtonPressed; }
		/**
		* @brief Get the dynamic event type of MouseButtonPressedEvent.
		* @return The EventType of the event.
		*/
		virtual EventType getEventType() const override { return getStaticType(); }
		/**
		* @brief Get the ID of the pressed mouse button.
		* @return The ID of the pressed mouse button.
		*/
		inline int32_t getButton() const { return m_button; }
	private:
		int32_t m_button; /**< The ID of the pressed mouse button. */
	};

	/**
	* @class MouseButtonReleaseEvent
	* @brief Event representing a mouse button being released.
	* The MouseButtonReleaseEvent class represents an event where a mouse button is released.
	* It provides information about the button that was released.
	*/
	class MouseButtonReleaseEvent : public MouseEvent
	{
	public:
		/**
		* @brief Constructor for MouseButtonReleaseEvent.
		* @param button The ID of the released mouse button.
		*/
		MouseButtonReleaseEvent(int32_t button) : m_button(button) {}

		/**
		* @brief Get the static event type of MouseButtonReleaseEvent.
		* @return The EventType of MouseButtonReleaseEvent.
		*/
		static EventType getStaticType() { return EventType::MouseButtonReleased; }

		/**
		* @brief Get the dynamic event type of MouseButtonReleaseEvent.
		* @return The EventType of the event.
		*/
		virtual EventType getEventType() const override { return getStaticType(); }

		/**
		* @brief Get the ID of the released mouse button.
		* @return The ID of the released mouse button.
		*/
		inline int32_t getButton() const { return m_button; }

	private:
		int32_t m_button; /**< The ID of the released mouse button. */
	};
}