/** \file entryPoint.h
*/
#pragma once
#include "core/window.h"
#include <GLFW/glfw3.h>

namespace Engine
{
	class GLFWWindowImpl : public Window
	{
	public:
		GLFWWindowImpl(const WindowProperties& properties);
		virtual void init(const WindowProperties& properties) override;
		virtual void close() override;
		virtual ~GLFWWindowImpl() {};
		virtual void onUpdate(float timestep) override;
		virtual void setVSync(bool VSync) override;
		virtual unsigned int getWidth() const override { return m_props.width; }
		virtual unsigned int getHeight() const override { return m_props.height; }
		virtual void* getNativeWindow() const override { return m_native; }
		virtual bool isFullScreenMode() const override { return m_props.isFullScreen; }
		virtual bool isVSync() const override { return m_props.isVSync; }

	private:
		WindowProperties m_props;
		GLFWwindow* m_native;
		float m_aspectRatio;
	};
}