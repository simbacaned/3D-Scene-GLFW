/** \file application.cpp
*/

#include "engine_pch.h"
#include "systems/timer.h";

namespace Engine
{
	float ChronoTimer::getTimeElapsed()
	{
		m_endPoint = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float, std::milli> elapsed = m_endPoint - m_startPoint;
		return elapsed.count() / 1000.0f;
	}
}