/** \file log.h
*/

#include <chrono>
#include "engine_pch.h"
#include "system.h";

namespace Engine
{
	class ChronoTimer
	{
	public:
		inline void start() { m_startPoint = std::chrono::high_resolution_clock::now(); }
		inline void reset() { m_startPoint = std::chrono::high_resolution_clock::now(); }
		float getTimeElapsed();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_endPoint;
	};
}
