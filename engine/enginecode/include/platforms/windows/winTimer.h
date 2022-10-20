/** \file entryPoint.h
*/
#pragma once

#include <Windows.h>
#include "core/timer.h"

namespace Engine
{
	/** \class WinTimer
	* Windows specific timer which use queryPerformanceCount
	*/
	class WinTimer : public Timer
	{
	public:
		virtual void start() override 
		{
			QueryPerformanceFrequency(&m_frequency);
			QueryPerformanceCounter(&m_startTime);
		};

		virtual inline void reset() override {QueryPerformanceCounter(&m_startTime);};

		virtual float getTimeElapsed() override
		{
			QueryPerformanceCounter(&m_endTime);
			float result = (m_endTime.QuadPart - m_startTime.QuadPart) * 1000.0f / m_frequency.QuadPart;
			result /= 1000.0f;
			return result;
		}
	private:
		LARGE_INTEGER m_startTime;
		LARGE_INTEGER m_endTime;
		LARGE_INTEGER m_frequency;
	};
}