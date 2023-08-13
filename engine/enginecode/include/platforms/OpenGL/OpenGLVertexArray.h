#pragma once

#include <vector>
#include <memory>
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Engine
{
	class OpenGLVertexArray
	{
	public:
		~OpenGLVertexArray();
		OpenGLVertexArray();
		void addVertexBuffer(const std::shared_ptr<OpenGLVertexBuffer>& vertexBuffer);
		void setIndexBuffer(const std::shared_ptr<OpenGLIndexBuffer>& indexBuffer);
		inline uint32_t getRenderID() const { return m_OpenGL_ID; }
		inline uint32_t getDrawCount() { if (m_indexBuffer) { return m_indexBuffer->getCount(); } else { return 0; } }
		void bind();
		void unbind();
	private:
		uint32_t m_OpenGL_ID; 
		uint32_t m_attributeIndex = 0; 
		std::vector<std::shared_ptr<OpenGLVertexBuffer>> m_vertexBuffer;
		std::shared_ptr<OpenGLIndexBuffer> m_indexBuffer;
	};
}