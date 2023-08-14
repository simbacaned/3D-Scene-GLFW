#include "engine_pch.h"
#include <glad/glad.h>
#include "platforms/OpenGL/OpenGLVertexBuffer.h"

namespace Engine
{
	void BufferLayout::addElement(BufferElement element)
	{
		// Add the provided element to the list of elements in the layout.
		m_elements.push_back(element);

		// Recalculate the stride and offsets after adding the element.
		calcStrideAndOffset();
	}

	void BufferLayout::calcStrideAndOffset()
	{
		// Initialize the offset to zero.
		uint32_t l_offset = 0;

		// Loop through each element in the layout.
		for (auto& element : m_elements)
		{
			// Assign the current offset to the element and update the offset.
			element.m_offset = l_offset;
			l_offset += element.m_size;
		}

		// Store the final calculated stride (total size of the layout) in m_stride.
		if (m_stride == 0) m_stride = l_offset;
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		// Delete the OpenGL buffer identified by m_OpenGL_ID.
		glDeleteBuffers(1, &m_OpenGL_ID);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(void* vertices, uint32_t size, BufferLayout layout) : m_layout(layout)
	{
		// Create a new OpenGL buffer and store its ID in m_OpenGL_ID.
		glCreateBuffers(1, &m_OpenGL_ID);

		// Bind the newly created buffer as an array buffer.
		glBindBuffer(GL_ARRAY_BUFFER, m_OpenGL_ID);

		// Fill the buffer with the provided vertex data.
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
	}

	void OpenGLVertexBuffer::edit(void* vertices, uint32_t size, uint32_t offset)
	{
		// Bind the vertex buffer for editing.
		glBindBuffer(GL_ARRAY_BUFFER, m_OpenGL_ID);

		// Update a portion of the buffer's data starting from the specified offset.
		glBufferSubData(GL_ARRAY_BUFFER, offset, size, vertices);
	}

	void OpenGLVertexBuffer::bind()
	{
		// Bind the OpenGL vertex buffer identified by m_OpenGL_ID.
		glBindBuffer(GL_ARRAY_BUFFER, m_OpenGL_ID);
	}

	void OpenGLVertexBuffer::unbind()
	{
		// Bind a null vertex buffer, effectively unbinding any currently bound vertex buffer.
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}