#pragma once

#include "rendering/bufferLayout.h"

namespace Engine
{
	class OpenGLVertexBuffer
	{
	public:
		~OpenGLVertexBuffer();
		OpenGLVertexBuffer(void* vertices, uint32_t size, BufferLayout layout);
		void edit(void* vertices, uint32_t size, uint32_t offset);
		inline uint32_t getRenderID() const { return m_OpenGL_ID; }
		inline const BufferLayout& getLayout() const { return m_layout; }
		void bind();
		void unbind();
	private:
		uint32_t m_OpenGL_ID; 
		BufferLayout m_layout;
	};
}