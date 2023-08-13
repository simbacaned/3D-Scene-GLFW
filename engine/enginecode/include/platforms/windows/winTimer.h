#pragma once

#include <Windows.h>
#include "core/timer.h"
#include <iostream>
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

		virtual inline float reset() override { QueryPerformanceCounter(&m_startTime); return getTimeElapsed(); };

		virtual float getTimeElapsed() override
		{
			float result = m_startTime.QuadPart - m_endTime.QuadPart;
			QueryPerformanceCounter(&m_endTime);
			return result / 10000000.0f;
		}
	private:
		LARGE_INTEGER m_startTime;
		LARGE_INTEGER m_endTime;
		LARGE_INTEGER m_frequency;
	};
}