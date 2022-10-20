/** \file timer.h
*/
#pragma once

#include <chrono>
#include "engine_pch.h"
#include "systems/system.h"

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
		virtual inline void start() override { m_startPoint = std::chrono::high_resolution_clock::now(); }
		virtual inline void reset() override { m_startPoint = std::chrono::high_resolution_clock::now(); }
		virtual float getTimeElapsed() override
		{
			m_endPoint = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> elapsed = m_endPoint - m_startPoint;
			return elapsed.count() / 1000.0f;
		};
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_endPoint;
	};
}