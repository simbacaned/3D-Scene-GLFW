#pragma once
#include "events/events.h";

#include <functional>

namespace Engine
{
	class EventHandler
	{
	public:
		void setOnCloseCallback(const std::function<bool(WindowCloseEvent&)>& fn) { m_onCloseCallback = fn; }
		std::function<bool(WindowCloseEvent&)>& getOnCloseCallback() { return m_onCloseCallback; }
	private:
		std::function<bool(WindowCloseEvent&)> m_onCloseCallback = std::bind(&EventHandler::defaultOnClose, this, std::placeholders::_1);
		bool defaultOnClose(WindowCloseEvent& e) { return false; }
	};
}
