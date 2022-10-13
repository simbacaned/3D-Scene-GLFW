/** \file log.h
*/
#pragma once
#include "system.h"
#include <spdlog/spdlog.h>
/**
\class Interface class for all systems
*/

namespace Engine
{
	class Log : public System
	{
	public:
		virtual void start(SystemSignal init = SystemSignal::None, ...);
		virtual void stop(SystemSignal close = SystemSignal::None, ...);

		template<class...Args>
		static void debug(Args&&...args);

		template<class...Args>
		static void error(Args&&...args);

		template<class...Args>
		static void info(Args&&...args);

		template<class...Args>
		static void trace(Args&&...args);

		template<class...Args>
		static void warn(Args&&...args);

		template<class...Args>
		static void release(Args&&...args);

		template<class...Args>
		static void file(Args&&...args);
	private:
		static std::shared_ptr<spdlog::logger> s_consoleLogger;
		static std::shared_ptr<spdlog::logger> s_fileLogger;
	};

	template<class...Args>
	static void Log::debug(Args&&...args)
	{
#ifdef NG_DEBUG
		s_consoleLogger->debug(std::forward<Args>(args)...);
#endif
	}

	template<class...Args>
	static void Log::error(Args&&...args)
	{
#ifdef NG_DEBUG
		s_consoleLogger->error(std::forward<Args>(args)...);
#endif
	}

	template<class...Args>
	static void Log::info(Args&&...args)
	{
#ifdef NG_DEBUG
		s_consoleLogger->info(std::forward<Args>(args)...);
#endif
	}

	template<class...Args>
	static void Log::trace(Args&&...args)
	{
#ifdef NG_DEBUG
		s_consoleLogger->trace(std::forward<Args>(args)...);
#endif
	}

	template<class...Args>
	static void Log::warn(Args&&...args)
	{
#ifdef NG_DEBUG
		s_consoleLogger->warn(std::forward<Args>(args)...);
#endif
	}

	template<class...Args>
	static void Log::release(Args&&...args)
	{
		s_consoleLogger->release(std::forward<Args>(args)...);
	}

	template<class...Args>
	static void Log::file(Args&&...args)
	{
		if(s_fileLogger)s_fileLogger->trace(std::forward<Args>(args)...);
	}
};