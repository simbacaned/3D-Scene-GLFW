/*****************************************************************//**
@file   cameraController.h
@brief  Basic Camera Controller base class, replace later on when ECS is implemented

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "cameras/camera.h"
#include "events/event.h"

class CameraController
{
public:
	Camera& getCamera() { return m_camera; }
	virtual void onUpdate(float t) {};
	virtual void onResize(Engine::WindowResizeEvent& e) {};
protected:
	Camera m_camera; //!< Camera being controlled
};
