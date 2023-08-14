/*****************************************************************//**
@file   GLFWSystem.h
@brief  This function is called by GLFW when an error occurs in the OpenGL context.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "systems/system.h"
#include "systems/log.h"

namespace Engine
{
    /**
    * @brief Error callback function used by GLFW for error reporting.
    * @param source The source of the error.
    * @param type The type of the error.
    * @param id The ID of the error.
    * @param severity The severity of the error.
    * @param length The length of the error message.
    * @param message The error message.
    * @param userParam A pointer to user-defined data (not typically used).
    */
    void errorCallback(
        GLenum source,
        GLenum type,
        GLenum id,
        GLenum severity,
        GLenum length,
        const GLchar* message,
        const void* userParam)
    {
        
    }

    /**
    * @brief Represents the GLFW-based System in the application.
    * This class provides the implementation for initializing and terminating
    * the GLFW system, which is used for managing the application's windowing and input.
    */
    class GLFWSystem : public System
    {
    public:
        /**
        * @brief Start the GLFW system.
        * This method initializes the GLFW system for windowing and input.
        *
        * @param init Signal indicating system initialization (default is SystemSignal::None).
        */
        virtual void start(SystemSignal init = SystemSignal::None, ...) override
        {
            auto errorCode = glfwInit();
            if (!errorCode)
            {
                Log::error("Cannot initialize GLFW: {0}", errorCode);
            }
        }

        /**
        * @brief Stop the GLFW system.
        * This method terminates the GLFW system and performs necessary cleanup.
        *
        * @param close Signal indicating system closure (default is SystemSignal::None).
        */
        virtual void stop(SystemSignal close = SystemSignal::None, ...) override
        {
            glfwTerminate();
        }
    };
}