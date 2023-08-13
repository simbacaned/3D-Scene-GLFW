#include "engine_pch.h"
#include "platforms/OpenGL/OpenGLIndexBuffer.h"
#include <glad/glad.h>

namespace Engine
{

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		// Delete the OpenGL buffer identified by m_OpenGL_ID.
		glDeleteBuffers(1, &m_OpenGL_ID);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count) : m_count(count)
	{
		// Create a new OpenGL buffer and store its ID in m_OpenGL_ID.
		glCreateBuffers(1, &m_OpenGL_ID);

		// Bind the newly created buffer as an element array buffer.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_OpenGL_ID);

		// Fill the buffer with the provided indices data.
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
	}

	void OpenGLIndexBuffer::bind()
	{
		// Bind the OpenGL index buffer identified by m_OpenGL_ID.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_OpenGL_ID);
	}

	void OpenGLIndexBuffer::unbind()
	{
		// Bind a null index buffer, effectively unbinding any currently bound index buffer.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}