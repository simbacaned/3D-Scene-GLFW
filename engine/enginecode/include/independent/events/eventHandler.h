/*****************************************************************//**
@file   eventHandler.h
@brief  provides a mechanism to manage event callback functions for different event types and default handlers.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include "events/events.h";

#include <functional>

namespace Engine
{
	/**
	* @class EventHandler
	* @brief Manages event callbacks and default handlers for various event types.
	*/
	class EventHandler
	{
	public:
		// Setter methods for event callbacks
		void setOnFocusCallback(const std::function<bool(WindowFocusEvent&)>& fn) { m_getOnFocusCallback = fn; }
		void setOnLostFocusCallback(const std::function<bool(WindowLostFocusEvent&)>& fn) { m_getOnLostFocusCallback = fn; }
		void setOnCloseCallback(const std::function<bool(WindowCloseEvent&)>& fn) { m_onCloseCallback = fn; }
		void setOnSizeCallback(const std::function<bool(WindowResizeEvent&)>& fn) { m_onSizeCallback = fn; }
		void setOnKeyPressedCallback(const std::function<bool(KeyPressedEvent&)>& fn) { m_onKeyPressedCallback = fn; }
		void setOnKeyReleasedCallback(const std::function<bool(KeyReleasedEvent&)>& fn) { m_onKeyReleasedCallback = fn; }
		void setOnMouseButtonPressedCallback(const std::function<bool(MouseButtonPressedEvent&)>& fn) { m_onMouseButtonPressedCallback = fn; }
		void setOnMouseButtonReleasedCallback(const std::function<bool(MouseButtonReleaseEvent&)>& fn) { m_onMouseButtonReleasedCallback = fn; }
		void setOnMouseMovedCallback(const std::function<bool(MouseMovedEvent&)>& fn) { m_onMouseMovedCallback = fn; }
		void setOnMouseScrollCallback(const std::function<bool(MouseScrolledEvent&)>& fn) { m_onMouseScrollCallback = fn; }
		// Getter methods for event callbacks
		std::function<bool(WindowFocusEvent&)>& getOnFocusCallback() { return m_getOnFocusCallback; }
		std::function<bool(WindowLostFocusEvent&)>& getOnLostFocusCallback() { return m_getOnLostFocusCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnCloseCallback() { return m_onCloseCallback; }
		std::function<bool(WindowResizeEvent&)>& getOnResizeCallback() { return m_onSizeCallback; }
		std::function<bool(KeyPressedEvent&)>& getOnKeyPressedCallback() { return m_onKeyPressedCallback; }
		std::function<bool(KeyReleasedEvent&)>& getOnKeyReleasedCallback() { return m_onKeyReleasedCallback; }
		std::function<bool(MouseButtonPressedEvent&)>& getOnMouseButtonPressedCallback() { return m_onMouseButtonPressedCallback; }
		std::function<bool(MouseButtonReleaseEvent&)>& getOnMouseButtonReleasedCallback() { return m_onMouseButtonReleasedCallback; }
		std::function<bool(MouseMovedEvent&)>& getOnMouseMovedCallback() { return m_onMouseMovedCallback; }
		std::function<bool(MouseScrolledEvent&)>& getOnMouseScrollCallback() { return m_onMouseScrollCallback; }
	private:
		// Default callback functions for event handling
		std::function<bool(WindowFocusEvent&)> m_getOnFocusCallback = std::bind(&EventHandler::defaultOnFocus, this, std::placeholders::_1);
		std::function<bool(WindowLostFocusEvent&)> m_getOnLostFocusCallback = std::bind(&EventHandler::defaultOnLostFocus, this, std::placeholders::_1);
		std::function<bool(WindowCloseEvent&)> m_onCloseCallback = std::bind(&EventHandler::defaultOnClose, this, std::placeholders::_1);
		std::function<bool(WindowResizeEvent&)> m_onSizeCallback = std::bind(&EventHandler::defaultOnResize, this, std::placeholders::_1);
		std::function<bool(KeyPressedEvent&)> m_onKeyPressedCallback = std::bind(&EventHandler::defaultOnKeyPressed, this, std::placeholders::_1);
		std::function<bool(KeyReleasedEvent&)> m_onKeyReleasedCallback = std::bind(&EventHandler::defaultOnKeyReleased, this, std::placeholders::_1);
		std::function<bool(MouseButtonPressedEvent&)> m_onMouseButtonPressedCallback = std::bind(&EventHandler::defaultOnMouseButtonPressed, this, std::placeholders::_1);
		std::function<bool(MouseButtonReleaseEvent&)> m_onMouseButtonReleasedCallback = std::bind(&EventHandler::defaultOnMouseButtonReleased, this, std::placeholders::_1);
		std::function<bool(MouseMovedEvent&)> m_onMouseMovedCallback = std::bind(&EventHandler::defaultOnMouseMoved, this, std::placeholders::_1);
		std::function<bool(MouseScrolledEvent&)> m_onMouseScrollCallback = std::bind(&EventHandler::defaultOnMouseScrollCall, this, std::placeholders::_1);
		// Default event handling callback functions
		bool defaultOnFocus(WindowFocusEvent& e) { return false; }
		bool defaultOnLostFocus(WindowLostFocusEvent& e) { return false; }
		bool defaultOnClose(WindowCloseEvent& e) { return false; }
		bool defaultOnResize(WindowResizeEvent& e) { return false; }
		bool defaultOnKeyPressed(KeyPressedEvent& e) { return false; }
		bool defaultOnKeyReleased(KeyReleasedEvent& e) { return false; }
		bool defaultOnMouseButtonPressed(MouseButtonPressedEvent& e) { return false; }
		bool defaultOnMouseButtonReleased(MouseButtonReleaseEvent& e) { return false; }
		bool defaultOnMouseMoved(MouseMovedEvent& e) { return false; }
		bool defaultOnMouseScrollCall(MouseScrolledEvent& e) { return false; }
	};
}
