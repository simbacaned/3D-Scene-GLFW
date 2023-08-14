/*****************************************************************//**
@file   GLFW_OpenGL_GC.h
@brief  This class provides an implementation of the GraphicsContext interface using GLFW for managing rendering with the OpenGL graphics API.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "core/graphicsContext.h"

namespace Engine
{
    /** @brief Represents a Graphics Context using GLFW for OpenGL rendering.*/
    class GLFW_OpenGL_GC : public GraphicsContext
    {
    public:
        /**
        * @brief Construct a new GLFW_OpenGL_GC object.
        * @param win The GLFW window associated with this graphics context.
        */
        GLFW_OpenGL_GC(GLFWwindow* win) : m_window(win) {}

        /**
        * @brief Initialize the OpenGL graphics context.
        * This method initializes the OpenGL graphics context, preparing it for rendering.
        * The specific behavior depends on the underlying GLFW window.
        */
        virtual void init() override;

        /**
        * @brief Swap the front and back buffers of the rendering context.
        * This method swaps the front and back buffers of the rendering context, presenting
        * the rendered image to the screen. This is typically used for double-buffering.
        */
        virtual void swapBuffers() override;

    private:
        GLFWwindow* m_window; //!< The GLFW window associated with this graphics context.
    };
}