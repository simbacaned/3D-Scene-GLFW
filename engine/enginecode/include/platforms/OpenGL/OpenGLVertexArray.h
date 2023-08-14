/*****************************************************************//**
@file   OpenGLVertexArray.h
@brief  This class provides functionality for creating and managing OpenGL vertex arrays by aggregating vertex buffer(s) and an optional index buffer.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <vector>
#include <memory>
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Engine
{
    /** @brief Class representing an OpenGL vertex array. */
    class OpenGLVertexArray
    {
    public:
        /**
        * @brief Destructor for OpenGLVertexArray.
        * Cleans up resources associated with the OpenGL vertex array.
        */
        ~OpenGLVertexArray();

        /**
        * @brief Constructor for OpenGLVertexArray.
        */
        OpenGLVertexArray();

        /**
        * @brief Add a vertex buffer to the vertex array.
        * @param vertexBuffer Shared pointer to the vertex buffer.
        */
        void addVertexBuffer(const std::shared_ptr<OpenGLVertexBuffer>& vertexBuffer);

        /**
        * @brief Set the index buffer for the vertex array.
        * @param indexBuffer Shared pointer to the index buffer.
        */
        void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

        /**
        * @brief Get the render ID of the vertex array.
        * @return The OpenGL render ID.
        */
        inline uint32_t getRenderID() const { return m_OpenGL_ID; }

        /**
        * @brief Get the draw count for rendering.
        * @return The draw count (number of indices) of the vertex array.
        */
        inline uint32_t getDrawCount() { return (m_indexBuffer) ? m_indexBuffer->getCount() : 0; }

        /**
        * @brief Bind the vertex array.
        */
        void bind();

        /**
        * @brief Unbind the vertex array.
        */
        void unbind();

    private:
        uint32_t m_OpenGL_ID; /**< The OpenGL vertex array ID. */
        uint32_t m_attributeIndex = 0; /**< The attribute index. */
        std::vector<std::shared_ptr<OpenGLVertexBuffer>> m_vertexBuffer; /**< Vector of shared pointers to vertex buffers. */
        std::shared_ptr<IndexBuffer> m_indexBuffer; /**< Shared pointer to the index buffer. */
    };
}