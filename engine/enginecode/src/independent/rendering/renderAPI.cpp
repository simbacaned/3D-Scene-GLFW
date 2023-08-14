#include "engine_pch.h"
#include "rendering/RenderAPI.h"
#include "systems/log.h"

#include "rendering/indexBuffer.h"
#include "platforms/OpenGL/OpenGLIndexBuffer.h"

namespace Engine
{
	RenderAPI::API RenderAPI::s_API = RenderAPI::API::OpenGL;

	IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t count)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::None:
			Log::error("Not having a rendering API is currently not supported");
			break;
		case RenderAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		case RenderAPI::API::Direct3D:
			Log::error("Direct3D is currently not supported");
			break;
		case RenderAPI::API::Vulkan:
			Log::error("Vulkan is currently not supported");
			break;
		}

		return nullptr;
	}
}