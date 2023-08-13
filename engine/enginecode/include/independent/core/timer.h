/*****************************************************************//**
@file   timer.h
@brief  The Timer class defines an abstract interface for managing timers and measuring time intervals.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <chrono>
#include "engine_pch.h"
#include "systems/system.h"

namespace Engine
{
	/**
	* @class Timer
	* @brief Abstract base class for timer interfaces.
	*/
	class Timer
	{
	public:
		/** @brief Start or reset the timer.*/
		virtual void start() = 0;

		/**
		* @brief Reset the timer and return the elapsed time.
		* @return The time elapsed since the timer was started or last reset, in seconds.
		*/
		virtual float reset() = 0;

		/**
		* @brief Get the time elapsed since the timer was started.
		* @return The time elapsed since the timer was started, in seconds.
		*/
		virtual float getTimeElapsed() = 0;
	};


	/**
	* @class ChronoTimer
	* @brief Implementation of the Timer interface using std::chrono.
	*
	* The ChronoTimer class implements the Timer interface using the std::chrono library for high-resolution timing.
	*/
	class ChronoTimer : public Timer {
	public:
		/** @brief Start the timer.*/
		virtual inline void start() override { m_startPoint = std::chrono::high_resolution_clock::now(); }

		/**
		* @brief Reset the timer and return the elapsed time.
		* @return The time elapsed since the timer was started or last reset, in seconds.
		*/
		virtual inline float reset() override { m_startPoint = std::chrono::high_resolution_clock::now(); return getTimeElapsed(); }

		/**
		* @brief Get the time elapsed since the timer was started.
		* @return The time elapsed since the timer was started, in seconds.
		*/
		virtual float getTimeElapsed() override {
			m_endPoint = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> elapsed = m_endPoint - m_startPoint;
			return elapsed.count() / 1000.0f;
		};
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint; /**< The starting time point for the timer. */
		std::chrono::time_point<std::chrono::high_resolution_clock> m_endPoint; /**< The ending time point for the timer. */
	};
}