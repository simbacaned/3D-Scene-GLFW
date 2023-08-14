/*****************************************************************//**
@file   cameraController.h
@brief  This class provides a base for camera controllers and contains a camera instance.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "cameras/camera.h"
#include "events/event.h"

 /**
* @class CameraController
* @brief Base class for camera controllers.
*/
class CameraController
{
public:
    /**
    * @brief Get the camera managed by the controller.
    * @return A reference to the camera managed by the controller.
    */
    Camera& getCamera() { return m_camera; }

    /**
    * @brief Callback for updating the camera controller.
    * @param t The time elapsed since the last update.
    * Subclasses can override this function to update the camera controller's behavior.
    */
    virtual void onUpdate(float t) {}

    /**
    * @brief Callback for handling window resize events.
    * @param e The window resize event.
    * Subclasses can override this function to handle window resize events affecting the camera.
    */
    virtual void onResize(Engine::WindowResizeEvent& e) {}

protected:
    Camera m_camera; /**< The camera managed by the controller. */
};
