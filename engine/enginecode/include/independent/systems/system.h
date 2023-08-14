/*****************************************************************//**
@file   system.h
@brief  This class serves as a foundation for various system components that need to be managed during the execution of the application

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <cstdarg>


namespace Engine {

    /** @brief Enumeration of system signals. */
    enum class SystemSignal { None = 0 };

    /** @brief Base class for system components. */
    class System
    {
    public:
        virtual ~System() {};

        /**
        * @brief Start the system.
        * @param init The initialization signal (default is SystemSignal::None).
        * @param ... Additional arguments for specific system start.
        */
        virtual void start(SystemSignal init = SystemSignal::None, ...) = 0;

        /**
        * @brief Stop the system.
        * @param close The closing signal (default is SystemSignal::None).
        * @param ... Additional arguments for specific system stop.
        */
        virtual void stop(SystemSignal close = SystemSignal::None, ...) = 0;
    };
}
