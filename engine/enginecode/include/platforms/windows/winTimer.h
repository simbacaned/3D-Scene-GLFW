/*****************************************************************//**
@file   winTimer.h
@brief  Windows specific timer which use queryPerformanceCount

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <Windows.h>
#include "core/timer.h"
#include <iostream>
namespace Engine
{
    /** @brief Class representing a high-resolution timer on Windows platform. */
    class WinTimer : public Timer
    {
    public:
        /**
        * @brief Start the timer.
        * Initializes the timer by capturing the current timestamp.
        */
        virtual void start() override
        {
            QueryPerformanceFrequency(&m_frequency);
            QueryPerformanceCounter(&m_startTime);
        };

        /**
        * @brief Reset the timer.
        * Resets the timer by capturing the current timestamp and returning the elapsed time.
        *
        * @return The elapsed time in seconds since the last reset.
        */
        virtual inline float reset() override { QueryPerformanceCounter(&m_startTime); return getTimeElapsed(); };

        /**
        * @brief Get the elapsed time.
        * Returns the time elapsed since the last reset or start operation.
        *
        * @return The elapsed time in seconds.
        */
        virtual float getTimeElapsed() override
        {
            float result = m_startTime.QuadPart - m_endTime.QuadPart;
            QueryPerformanceCounter(&m_endTime);
            return result / 10000000.0f;
        }

    private:
        LARGE_INTEGER m_startTime;   /**< The start time captured using QueryPerformanceCounter. */
        LARGE_INTEGER m_endTime;     /**< The end time captured using QueryPerformanceCounter. */
        LARGE_INTEGER m_frequency;   /**< The frequency of the high-resolution timer. */
    };
}