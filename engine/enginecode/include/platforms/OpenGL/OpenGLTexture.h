/*****************************************************************//**
@file   OpenGLTexture.h
@brief  This class provides functionality for creating and managing OpenGL textures, whether loaded from an image file or generated from raw data.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <cstdint>

namespace Engine
{
    /** @brief Class representing an OpenGL texture. */
    class OpenGLTexture
    {
    public:
        /**
        * @brief Constructor for OpenGLTexture from file.
        * Constructs an OpenGL texture by loading the texture data from the provided
        * image file.
        *
        * @param filepath Path to the image file.
        */
        OpenGLTexture(const char* filepath);

        /**
        * @brief Constructor for OpenGLTexture from raw data.
        * Constructs an OpenGL texture from raw pixel data with the specified width,
        * height, and number of channels.
        *
        * @param width Width of the texture.
        * @param height Height of the texture.
        * @param channels Number of color channels.
        * @param data Raw pixel data.
        */
        OpenGLTexture(uint32_t width, uint32_t height, uint32_t channels, unsigned char* data);

        /**
        * @brief Destructor for OpenGLTexture.
        * Cleans up resources associated with the OpenGL texture.
        */
        ~OpenGLTexture();

        /**
        * @brief Edit a portion of the texture.
        * Edits a rectangular region of the texture with new pixel data.
        *
        * @param xOffset X-coordinate of the starting point.
        * @param yOffset Y-coordinate of the starting point.
        * @param width Width of the region to edit.
        * @param height Height of the region to edit.
        * @param data New pixel data for the region.
        */
        void edit(uint32_t xOffset, uint32_t yOffset, uint32_t width, uint32_t height, unsigned char* data);

        /**
        * @brief Get the OpenGL ID of the texture.
        * @return The OpenGL texture ID.
        */
        inline uint32_t getID() { return m_OpenGL_ID; }

        /**
        * @brief Get the width of the texture.
        * @return The width of the texture.
        */
        inline uint32_t getWidth() { return m_width; }

        /**
        * @brief Get the height of the texture.
        * @return The height of the texture.
        */
        inline uint32_t getHeight() { return m_height; }

        /**
        * @brief Get the number of color channels in the texture.
        * @return The number of color channels.
        */
        inline uint32_t getChannels() { return m_channels; }

    private:
        uint32_t m_OpenGL_ID; /**< The OpenGL texture ID. */
        uint32_t m_width; /**< The width of the texture. */
        uint32_t m_height; /**< The height of the texture. */
        uint32_t m_channels; /**< The number of color channels. */

        /**
        * @brief Initialize the texture with raw data.
        * Initializes the OpenGL texture with the provided raw pixel data.
        *
        * @param width Width of the texture.
        * @param height Height of the texture.
        * @param channels Number of color channels.
        * @param data Raw pixel data.
        */
        void init(uint32_t width, uint32_t height, uint32_t channels, unsigned char* data);
    };
}