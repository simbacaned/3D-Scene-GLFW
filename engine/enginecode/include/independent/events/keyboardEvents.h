/*****************************************************************//**
@file   keyboardEvents.h
@brief  The keyboardEvents class serves as the base class for events related to keyboard keys.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include "event.h"
#include <glm/glm.hpp>

namespace Engine
{
	/**
	* @class KeyEvent
	* @brief Base class for key-related events.
	*/
	class KeyEvent : public Event
	{
	protected:
		/**
		* @brief Constructor for KeyEvent.
		* @param keycode The keycode of the pressed or released key.
		*/
		KeyEvent(int32_t keycode) : m_keyCode(keycode) {}

		int32_t m_keyCode; /**< The keycode of the pressed or released key. */
	public:
		/**
		* @brief Get the keycode of the key associated with the event.
		* @return The keycode of the key.
		*/
		inline int32_t getKeyCode() const { return m_keyCode; }

		/**
		* @brief Get the category flags associated with the event.
		* @return The category flags, including EventCategoryKeyboard and EventCategoryInput.
		*/
		virtual inline int32_t getCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }
	};

	/**
	* @class KeyPressedEvent
	* @brief Event representing a key being pressed.
	*/
	class KeyPressedEvent : public KeyEvent
	{
	public:
		/**
		* @brief Constructor for KeyPressedEvent.
		* @param keycode The keycode of the pressed key.
		* @param repeatCount The number of times the key was repeated.
		*/
		KeyPressedEvent(int32_t keycode, int32_t repeatCount) : KeyEvent(keycode), m_repeatCount(repeatCount) {}

		/**
		* @brief Get the repeat count of the key press.
		* @return The number of times the key was repeated.
		*/
		inline int32_t getRepeatCount() const { return m_repeatCount; }

		/**
		* @brief Get the static event type of KeyPressedEvent.
		* @return The EventType of KeyPressedEvent.
		*/
		static EventType getStaticType() { return EventType::KeyPressed; }

		/**
		* @brief Get the dynamic event type of KeyPressedEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return getStaticType(); }

	private:
		int32_t m_repeatCount; /**< The repeat count of the key press. */
	};

	/**
	* @class KeyReleasedEvent
	* @brief Event representing a key being released.
	*/
	class KeyReleasedEvent : public KeyEvent
	{
	public:
		/**
		* @brief Constructor for KeyReleasedEvent.
		* @param keycode The keycode of the released key.
		*/
		KeyReleasedEvent(int32_t keycode) : KeyEvent(keycode) {}

		/**
		* @brief Get the static event type of KeyReleasedEvent.
		* @return The EventType of KeyReleasedEvent.
		*/
		static EventType getStaticType() { return EventType::KeyReleased; }

		/**
		* @brief Get the dynamic event type of KeyReleasedEvent.
		* @return The EventType of the event.
		*/
		virtual inline EventType getEventType() const override { return getStaticType(); }
	};
}