/** \file log.h
*/

#include <chrono>
#include "engine_pch.h"
#include "system.h";

namespace Engine
{
	class Timer
	{
	public:
		virtual void start() = 0;
		virtual void reset() = 0;
		virtual float getTimeElapsed() = 0;
	};

	class ChronoTimer : public Timer
	{
	public:
		virtual inline void start() { m_startPoint = std::chrono::high_resolution_clock::now(); }
		virtual inline void reset() { m_startPoint = std::chrono::high_resolution_clock::now(); }
		virtual float getTimeElapsed();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_endPoint;
	};
}
