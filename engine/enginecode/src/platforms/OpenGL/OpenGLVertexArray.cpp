#include "engine_pch.h"
#include <glad/glad.h>
#include "platforms/OpenGL/OpenGLVertexArray.h"

namespace Engine
{
	namespace SDT
	{
		// converts a custom ShaderDataType to its corresponding OpenGL GLenum type.
		static GLenum toGLType(ShaderDataType type)
		{
			// maps different ShaderDataType values to their corresponding OpenGL types.
			switch (type)
			{
			case ShaderDataType::Float: return GL_FLOAT;    // Convert Float to GL_FLOAT
			case ShaderDataType::Float2: return GL_FLOAT;   // Convert Float2 to GL_FLOAT
			case ShaderDataType::Float3: return GL_FLOAT;   // Convert Float3 to GL_FLOAT
			case ShaderDataType::Float4: return GL_FLOAT;   // Convert Float4 to GL_FLOAT
			default: return GL_INVALID_ENUM;                // Return GL_INVALID_ENUM for unsupported types
			}
		}
	}

	// Destructor: Responsible for cleaning up the OpenGL vertex array object.
	OpenGLVertexArray::~OpenGLVertexArray()
	{
		// Delete the OpenGL vertex array identified by m_OpenGL_ID
		glDeleteVertexArrays(1, &m_OpenGL_ID);
	}

	// Constructor: Initializes the OpenGL vertex array object.
	OpenGLVertexArray::OpenGLVertexArray()
	{
		// Create a new OpenGL vertex array and store its ID in m_OpenGL_ID
		glCreateVertexArrays(1, &m_OpenGL_ID);

		// Bind the newly created vertex array
		glBindVertexArray(m_OpenGL_ID);
	}

	// Method to add a vertex buffer to the vertex array.
	void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<OpenGLVertexBuffer>& vertexBuffer)
	{
		// Bind this vertex array so that vertex buffer settings are applied to it.
		glBindVertexArray(m_OpenGL_ID);

		// Bind the specified vertex buffer to the OpenGL context.
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->getRenderID());

		// Get the layout (vertex attributes) of the vertex buffer.
		const auto& layout = vertexBuffer->getLayout();

		// Loop through each element (attribute) in the layout.
		for (auto& element : layout)
		{
			uint32_t normalised = GL_FALSE;

			// Check if the attribute needs to be normalized.
			if (element.m_normalised) { normalised = GL_TRUE; }

			// Enable the vertex attribute at m_attributeIndex.
			glEnableVertexAttribArray(m_attributeIndex);

			// Specify the layout and properties of the vertex attribute.
			glVertexAttribPointer(
				m_attributeIndex,
				SDT::componentCount(element.m_dataType),     // Number of components in the attribute.
				SDT::toGLType(element.m_dataType),           // OpenGL data type of the attribute.
				normalised,
				layout.getStride(),                         // Distance between consecutive attributes.
				(void*)element.m_offset);                   // Offset of the attribute in the vertex buffer.

			// Move to the next attribute index.
			m_attributeIndex++;
		}
	}

	// Method to set the index buffer for the vertex array.
	void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<OpenGLIndexBuffer>& indexBuffer)
	{
		// Store the provided index buffer in the member variable m_indexBuffer.
		m_indexBuffer = indexBuffer;
	}

	// Method to bind the vertex array for rendering.
	void OpenGLVertexArray::bind()
	{
		// Bind the OpenGL vertex array identified by m_OpenGL_ID.
		glBindVertexArray(m_OpenGL_ID);
	}

	// Method to unbind the currently bound vertex array.
	void OpenGLVertexArray::unbind()
	{
		// Bind a null vertex array, effectively unbinding any currently bound vertex array.
		glBindVertexArray(0);
	}
}