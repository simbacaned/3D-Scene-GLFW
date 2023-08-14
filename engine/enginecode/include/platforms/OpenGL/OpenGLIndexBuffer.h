/*****************************************************************//**
@file   OpenGLIndexBuffer.h
@brief  Represents an OpenGL index buffer used for rendering indexed geometry.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <cstdint>
#include "rendering/indexBuffer.h"

namespace Engine
{
	/**
	* @class OpenGLIndexBuffer
	* @brief Represents an OpenGL index buffer used for rendering indexed geometry.
	*/
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		/** @brief Destructor, responsible for cleaning up the OpenGL index buffer.*/
		~OpenGLIndexBuffer();
		/**
		* @brief Constructor, creates an OpenGL index buffer with provided indices data and count.
		* @param indices Pointer to the array of indices.
		* @param count Number of indices in the buffer.
		*/
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		/**
		* @brief Get the OpenGL render identifier of the buffer.
		* Returns the OpenGL identifier associated with the buffer.
		* @return The OpenGL render identifier of the buffer.
		*/
		inline uint32_t getRenderID() const { return m_OpenGL_ID; }
		/**
		* @brief Get the count of elements in the buffer.
		* Returns the number of elements contained in the buffer.
		* @return The count of elements in the buffer.
		*/
		inline uint32_t getCount() const { return m_count; }
		/** @brief Method to bind the index buffer for rendering.*/
		void bind();
		/** @brief  Method to unbind the currently bound index buffer.*/
		void unbind();
	private:
		uint32_t m_OpenGL_ID; /**< The OpenGL identifier of the index buffer. */
		uint32_t m_count; /**< The number of indices in the index buffer. */
	};
}