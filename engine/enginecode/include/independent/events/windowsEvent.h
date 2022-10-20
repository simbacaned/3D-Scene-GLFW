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

		inline int32_t getWidth() const { return m_width; }
		inline int32_t getHeight() const { return m_height; }
		inline glm::ivec2 getSize() const { return { m_width, m_height }; }
	private:
		int32_t m_width;
		int32_t m_height;
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}
		static EventType getStaticType() { return EventType::WindowFocus; }
		virtual inline EventType getEventType() const override { return EventType::WindowFocus; }
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}
		static EventType getStaticType() { return EventType::WindowLostFocus; }
		virtual inline EventType getEventType() const override { return EventType::WindowLostFocus; }
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; }
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int32_t x, int32_t y) : m_xPos(x), m_yPos(y) {}
		static EventType getStaticType() { return EventType::WindowMoved; }
		virtual inline EventType getEventType() const override { return EventType::WindowMoved; }
		inline int32_t getXPos() const { return m_xPos; }
		inline int32_t getYPos() const { return m_yPos; }
	private:
		int32_t m_xPos;
		int32_t m_yPos;

	};
}
