/*****************************************************************//**
@file   log.h
@brief  This class allows logging messages with different severity levels and directing them to the console or a file.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include "system.h"
#include <spdlog/spdlog.h>
/**
\class Interface class for all systems
*/

namespace Engine
{
    /**
    * @class Log
    * @brief Provides logging functionality using spdlog.
    */
    class Log : public System
    {
    public:
        /**
        * @brief Start the logging system.
        * @param init The initialization signal for the system (optional).
        * @param ... Additional arguments for system initialization (optional).
        */
        virtual void start(SystemSignal init = SystemSignal::None, ...);
        /**
        * @brief Stop the logging system.
        * @param close The closing signal for the system (optional).
        * @param ... Additional arguments for system closure (optional).
        */
        virtual void stop(SystemSignal close = SystemSignal::None, ...);
        /**
        * @brief Log a debug message.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void debug(Args&&... args);
        /**
        * @brief Log an error message.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void error(Args&&... args);
        /**
        * @brief Log an informational message.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void info(Args&&... args);
        /**
        * @brief Log a trace message.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void trace(Args&&... args);
        /**
        * @brief Log a warning message.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void warn(Args&&... args);
        /**
        * @brief Log a release message.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void release(Args&&... args);
        /**
        * @brief Log a message to a file.
        * @param args The arguments to format and log.
        * @tparam Args Variadic template for message arguments.
        */
        template<class... Args>
        static void file(Args&&... args);

    private:
        static std::shared_ptr<spdlog::logger> s_consoleLogger; /**< Logger for console output. */
        static std::shared_ptr<spdlog::logger> s_fileLogger;    /**< Logger for file output. */
    };

    /**
    * @brief Log a debug message.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::debug(Args&&... args)
    {
#ifdef NG_DEBUG
        s_consoleLogger->debug(std::forward<Args>(args)...);
#endif
    }

    /**
    * @brief Log an error message.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::error(Args&&... args)
    {
#ifdef NG_DEBUG
        s_consoleLogger->error(std::forward<Args>(args)...);
#endif
    }

    /**
    * @brief Log an informational message.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::info(Args&&... args)
    {
#ifdef NG_DEBUG
        s_consoleLogger->info(std::forward<Args>(args)...);
#endif
    }

    /**
    * @brief Log a trace message.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::trace(Args&&... args)
    {
#ifdef NG_DEBUG
        s_consoleLogger->trace(std::forward<Args>(args)...);
#endif
    }

    /**
    * @brief Log a warning message.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::warn(Args&&... args)
    {
#ifdef NG_DEBUG
        s_consoleLogger->warn(std::forward<Args>(args)...);
#endif
    }

    /**
    * @brief Log a release message.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::release(Args&&... args)
    {
        s_consoleLogger->release(std::forward<Args>(args)...);
    }

    /**
    * @brief Log a message to a file.
    * @param args The arguments to format and log.
    * @tparam Args Variadic template for message arguments.
    */
    template<class... Args>
    static void Log::file(Args&&... args)
    {
        if (s_fileLogger) s_fileLogger->trace(std::forward<Args>(args)...);
    }
};