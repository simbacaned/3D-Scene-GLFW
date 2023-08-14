/*****************************************************************//**
@file   GLFWWindowImpl.h
@brief  This class provides the implementation for creating, initializing, and managing a window using the GLFW library for windowing and input handling.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once
#include <GLFW/glfw3.h>
#include "core/window.h"

namespace Engine
{
    /**
    * @brief Implementation of a window using the GLFW library.
    */
    class GLFWWindowImpl : public Window
    {
    public:
        /**
        * @brief Constructor for GLFWWindowImpl.
        * Initializes the GLFW window implementation with the provided properties.
        *
        * @param properties The properties of the window to be created.
        */
        GLFWWindowImpl(const WindowProperties& properties);

        /**
        * @brief Initialize the GLFW window.
        * This method initializes the GLFW window with the specified properties.
        *
        * @param properties The properties of the window to be initialized.
        */
        virtual void init(const WindowProperties& properties) override;

        /**
        * @brief Close the GLFW window.
        * This method closes and terminates the GLFW window.
        */
        virtual void close() override;

        /**
        * @brief Destructor for GLFWWindowImpl.
        * Cleans up resources associated with the GLFW window.
        */
        virtual ~GLFWWindowImpl() {};

        /**
        * @brief Update the GLFW window.
        * This method updates the GLFW window using the provided time step.
        *
        * @param timestep The time step used for updating the window.
        */
        virtual void onUpdate(float timestep) override;

        /**
        * @brief Set the vertical synchronization (V-Sync) of the GLFW window.
        * This method sets the vertical synchronization (V-Sync) mode of the GLFW window.
        *
        * @param VSync Set to true to enable V-Sync, false to disable.
        */
        virtual void setVSync(bool VSync) override;

        /**
        * @brief Get the width of the GLFW window.
        * @return The width of the GLFW window.
        */
        virtual unsigned int getWidth() const override { return m_props.width; }

        /**
        * @brief Get the height of the GLFW window.
        * @return The height of the GLFW window.
        */
        virtual unsigned int getHeight() const override { return m_props.height; }

        /**
        * @brief Get a pointer to the native GLFW window.
        * @return A pointer to the native GLFW window object.
        */
        virtual void* getNativeWindow() const override { return m_native; }

        /**
        * @brief Check if the GLFW window is in fullscreen mode.
        * @return True if the GLFW window is in fullscreen mode, false otherwise.
        */
        virtual bool isFullScreenMode() const override { return m_props.isFullScreen; }

        /**
        * @brief Check if V-Sync is enabled for the GLFW window.
        * @return True if V-Sync is enabled, false otherwise.
        */
        virtual bool isVSync() const override { return m_props.isVSync; }

    private:
        WindowProperties m_props;   /**< The properties of the GLFW window. */
        GLFWwindow* m_native;       /**< A pointer to the native GLFW window object. */
        float m_aspectRatio;        /**< The aspect ratio of the window. */
    };
}