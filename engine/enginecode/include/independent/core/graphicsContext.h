/** \file timer.h
*/
#pragma once

namespace
{
	class GraphicsContext
	{
	public: 
		virtual void init() = 0;
		virtual void swapBuffers() = 0;
	};
}