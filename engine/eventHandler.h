#pragma once
#include "events/events.h";

#include <functional>

namespace Engine
{
	class EventHandler
	{
	public:
		void setOnCloseCallback(const std::function<bool(WindowCloseEvent&)>& fn) { m_onCloseCallback = fn; }
		void setOnResizeCallback(const std::function<bool(WindowResizeEvent&)>& fn) { m_onResizeCallback = fn; }
		void setOnFocusback(const std::function<bool(WindowFocusEvent&)>& fn) { m_onFocusCallback = fn; }
		void setOnLostFocusCallback(const std::function<bool(WindowLostFocusEvent&)>& fn) { m_onLostFocusCallback = fn; }
		void setOnWindowMovedCallback(const std::function<bool(WindowMovedEvent&)>& fn) { m_onWindowMovedCallback = fn; }
		void setOnKeyPressedCallback(const std::function<bool(KeyPressedEvent&)>& fn) { m_onKeyPressedCallback = fn; }
		void setOnKeyReleasedCallback(const std::function<bool(KeyReleasedEvent&)>& fn) { m_onKeyReleasedCallback = fn; }
		void setOnMouseButtonDownCallback(const std::function<bool(MouseButtonPressedEvent&)>& fn) { m_onMouseButtonDownCallback = fn; }
		void setOnMouseButtonReleasedCallback(const std::function<bool(MouseButtonReleaseEvent&)>& fn) { m_onMouseButtonReleasedCallback = fn; }
		void setOnMouseMovedCallback(const std::function<bool(MouseMovedEvent&)>& fn) { m_onMouseMovedCallback = fn; }
		void setOnMouseWheelCallback(const std::function<bool(MouseScrolledEvent&)>& fn) { m_onMouseWheelCallback = fn; }

		std::function<bool(WindowCloseEvent&)>& getOnCloseCallback() { return m_onCloseCallback; }
		std::function<bool(WindowResizeEvent&)>& setOnResizeCallback() { return m_onResizeCallback; }
		std::function<bool(WindowFocusEvent&)>& setOnFocusback() { return m_onFocusCallback; }
		std::function<bool(WindowLostFocusEvent&)>& setOnLostFocusCallback() { return m_onLostFocusCallback; }
		std::function<bool(WindowMovedEvent&)>& setOnWindowMovedCallback() { return m_onWindowMovedCallback; }
		std::function<bool(KeyPressedEvent&)>& setOnKeyPressedCallback() { return m_onKeyPressedCallback; }
		std::function<bool(KeyReleasedEvent&)>& setOnKeyReleasedCallback() { return m_onKeyReleasedCallback; }
		std::function<bool(MouseButtonPressedEvent&)>& setOnMouseButtonDownCallback() { return m_onMouseButtonDownCallback; }
		std::function<bool(MouseButtonReleaseEvent&)>& setOnMouseButtonReleasedCallback() { return m_onMouseButtonReleasedCallback; }
		std::function<bool(MouseMovedEvent&)>& setOnMouseMovedCallback() { return m_onMouseMovedCallback; }
		std::function<bool(MouseScrolledEvent&)>& setOnMouseWheelCallback() { return m_onMouseWheelCallback; }
	private:
		std::function<bool(WindowCloseEvent&)> m_onCloseCallback = std::bind(&EventHandler::defaultOnClose, this, std::placeholders::_1);
		std::function<bool(WindowResizeEvent&)> m_onResizeCallback = std::bind(&EventHandler::defaultOnResize, this, std::placeholders::_1);
		std::function<bool(WindowFocusEvent&)> m_onFocusCallback = std::bind(&EventHandler::defaultOnFocus, this, std::placeholders::_1);
		std::function<bool(WindowLostFocusEvent&)> m_onLostFocusCallback = std::bind(&EventHandler::defaultOnLostFocus, this, std::placeholders::_1);
		std::function<bool(WindowMovedEvent&)> m_onWindowMovedCallback = std::bind(&EventHandler::defaultOnWindowMoved, this, std::placeholders::_1);
		std::function<bool(KeyPressedEvent&)> m_onKeyPressedCallback = std::bind(&EventHandler::defaultOnKeyPressed, this, std::placeholders::_1);
		std::function<bool(KeyReleasedEvent&)> m_onKeyReleasedCallback = std::bind(&EventHandler::defaultOnKeyReleased, this, std::placeholders::_1);
		std::function<bool(MouseButtonPressedEvent&)> m_onMouseButtonDownCallback = std::bind(&EventHandler::defaultOnMouseButtonDown, this, std::placeholders::_1);
		std::function<bool(MouseButtonReleaseEvent&)> m_onMouseButtonReleasedCallback = std::bind(&EventHandler::defaultOnMouseButtonReleased, this, std::placeholders::_1);
		std::function<bool(MouseMovedEvent&)> m_onMouseMovedCallback = std::bind(&EventHandler::defaultOnMouseMoved, this, std::placeholders::_1);
		std::function<bool(MouseScrolledEvent&)> m_onMouseWheelCallback = std::bind(&EventHandler::defaultOnMouseWheel, this, std::placeholders::_1);

		bool defaultOnClose(WindowCloseEvent& e) { return false; }
		bool defaultOnResize(WindowResizeEvent& e) { return false; }
		bool defaultOnFocus(WindowFocusEvent& e) { return false; }
		bool defaultOnLostFocus(WindowLostFocusEvent& e) { return false; }
		bool defaultOnWindowMoved(WindowMovedEvent& e) { return false; }
		bool defaultOnKeyPressed(KeyPressedEvent& e) { return false; }
		bool defaultOnKeyReleased(KeyReleasedEvent& e) { return false; }
		bool defaultOnMouseButtonDown(MouseButtonPressedEvent& e) { return false; }
		bool defaultOnMouseButtonReleased(MouseButtonReleaseEvent& e) { return false; }
		bool defaultOnMouseMoved(MouseMovedEvent& e) { return false; }
		bool defaultOnMouseWheel(MouseScrolledEvent& e) { return false; }

	};
}
