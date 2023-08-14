/*****************************************************************//**
@file   OpenGLVertexBuffer.h
@brief  This class provides functionality for creating and managing OpenGL vertex buffers.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "rendering/bufferLayout.h"

namespace Engine
{
    /** @brief Class representing an OpenGL vertex buffer. */
    class OpenGLVertexBuffer
    {
    public:
        /**
        * @brief Destructor for OpenGLVertexBuffer.
        * Cleans up resources associated with the OpenGL vertex buffer.
        */
        ~OpenGLVertexBuffer();

        /**
        * @brief Constructor for OpenGLVertexBuffer.
        * @param vertices Pointer to the vertex data.
        * @param size Size of the vertex data in bytes.
        * @param layout Buffer layout specifying vertex attributes.
        */
        OpenGLVertexBuffer(void* vertices, uint32_t size, BufferLayout layout);

        /**
        * @brief Edit the vertex buffer's data.
        * @param vertices Pointer to the new vertex data.
        * @param size Size of the new vertex data in bytes.
        * @param offset Offset at which to write the new data.
        */
        void edit(void* vertices, uint32_t size, uint32_t offset);

        /**
        * @brief Get the render ID of the vertex buffer.
        * @return The OpenGL render ID.
        */
        inline uint32_t getRenderID() const { return m_OpenGL_ID; }

        /**
        * @brief Get the layout of the vertex buffer.
        * @return The buffer layout specifying vertex attributes.
        */
        inline const BufferLayout& getLayout() const { return m_layout; }

        /**
        * @brief Bind the vertex buffer.
        * Binds the vertex buffer for rendering.
        */
        void bind();

        /**
        * @brief Unbind the vertex buffer.
        * Unbinds the vertex buffer.
        */
        void unbind();

    private:
        uint32_t m_OpenGL_ID; /**< The OpenGL vertex buffer ID. */
        BufferLayout m_layout; /**< The layout specifying vertex attributes. */
    };
}