/*****************************************************************//**
@file   windowsEvent.h
@brief  Serves as the base class for events related to mouse window interactions.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include "event.h"
#include <glm/glm.hpp>

namespace Engine 
{
	/**
	* @class WindowCloseEvent
	* @brief Event representing the window close action.
	* The WindowCloseEvent class represents an event triggered when the window is being closed.
	*/
	class WindowCloseEvent : public Event
	{
	public:
		/**
		* @brief Get the static event type of WindowCloseEvent.
		* @return The EventType of WindowCloseEvent.
		*/
		static EventType getStaticType() { return EventType::WindowClose; }

		/**
		* @brief Get the dynamic event type of WindowCloseEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return EventType::WindowClose; }

		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags for a window event.
		*/
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	};

	/**
	* @class WindowResizeEvent
	* @brief Event representing the window resize action.
	* The WindowResizeEvent class represents an event triggered when the window is resized.
	* It provides information about the new dimensions of the window.
	*/
	class WindowResizeEvent : public Event
	{
	public:
		/**
		* @brief Constructor for WindowResizeEvent.
		* @param width The new width of the window.
		* @param height The new height of the window.
		*/
		WindowResizeEvent(int32_t width, int32_t height) : m_width(width), m_height(height) {}

		/**
		* @brief Get the static event type of WindowResizeEvent.
		* @return The EventType of WindowResizeEvent.
		*/
		static EventType getStaticType() { return EventType::WindowResize; }

		/**
		* @brief Get the dynamic event type of WindowResizeEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return EventType::WindowResize; }

		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags for a window event.
		*/
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }

		/**
		* @brief Get the width of the resized window.
		* @return The new width of the window.
		*/
		inline int32_t getWidth() const { return m_width; }

		/**
		* @brief Get the height of the resized window.
		* @return The new height of the window.
		*/
		inline int32_t getHeight() const { return m_height; }

		/**
		* @brief Get the size of the resized window as a 2D vector.
		* @return The new dimensions of the window as a glm::ivec2.
		*/
		inline glm::ivec2 getSize() const { return { m_width, m_height }; }

	private:
		int32_t m_width; /**< The new width of the window. */
		int32_t m_height; /**< The new height of the window. */
	};

	/**
	* @class WindowFocusEvent
	* @brief Event representing the window focus action.
	* The WindowFocusEvent class represents an event triggered when the window gains focus.
	* It indicates that the window has become the active and focused window.
	*/
	class WindowFocusEvent : public Event
	{
	public:
		/** @brief Constructor for WindowFocusEvent.*/
		WindowFocusEvent() {}

		/**
		* @brief Get the static event type of WindowFocusEvent.
		* @return The EventType of WindowFocusEvent.
		*/
		static EventType getStaticType() { return EventType::WindowFocus; }

		/**
		* @brief Get the dynamic event type of WindowFocusEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return EventType::WindowFocus; }

		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags for a window event.
		*/
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	};

	/**
	* @class WindowLostFocusEvent
	* @brief Event representing the window lost focus action.
	* The WindowLostFocusEvent class represents an event triggered when the window loses focus.
	* It indicates that the window is no longer the active and focused window.
	*/
	class WindowLostFocusEvent : public Event
	{
	public:
		/** @brief Constructor for WindowLostFocusEvent.*/
		WindowLostFocusEvent() {}

		/**
		* @brief Get the static event type of WindowLostFocusEvent.
		* @return The EventType of WindowLostFocusEvent.
		*/
		static EventType getStaticType() { return EventType::WindowLostFocus; }

		/**
		* @brief Get the dynamic event type of WindowLostFocusEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return EventType::WindowLostFocus; }

		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags for a window event.
		*/
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	};

	/**
	* @class WindowMovedEvent
	* @brief Event representing the window moved action.
	* The WindowMovedEvent class represents an event triggered when the window is moved.
	* It provides the new position of the window after the move.
	*/
	class WindowMovedEvent : public Event
	{
	public:
		/**
		* @brief Constructor for WindowMovedEvent.
		* @param x The new x-coordinate of the window.
		* @param y The new y-coordinate of the window.
		*/
		WindowMovedEvent(int32_t x, int32_t y) : m_xPos(x), m_yPos(y) {}

		/**
		* @brief Get the static event type of WindowMovedEvent.
		* @return The EventType of WindowMovedEvent.
		*/
		static EventType getStaticType() { return EventType::WindowMoved; }

		/**
		* @brief Get the dynamic event type of WindowMovedEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return EventType::WindowMoved; }

		/**
		* @brief Get the x-coordinate of the new window position.
		* @return The x-coordinate of the window.
		*/
		inline int32_t getXPos() const { return m_xPos; }

		/**
		* @brief Get the y-coordinate of the new window position.
		* @return The y-coordinate of the window.
		*/
		inline int32_t getYPos() const { return m_yPos; }

	private:
		int32_t m_xPos; /**< The x-coordinate of the new window position. */
		int32_t m_yPos; /**< The y-coordinate of the new window position. */
	};
}
