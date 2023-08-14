/*****************************************************************//**
@file   cameraControllerEuler.h
@brief  Euler Camera Controller class

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "cameras/cameraController.h"
#include "events/InputPoller.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

    /** @brief Properties struct for FPSEulerCameraController. */
    struct FPSEulerCameraProps
    {
        glm::vec3 position = glm::vec3(0.0f); /**< The initial position of the camera. */
        float yaw = 0.0f; /**< The initial yaw angle in degrees. */
        float pitch = 0.0f; /**< The initial pitch angle in degrees. */
        float translationSpeed = 2.0f; /**< The translation speed of the camera. */
        float rotationSpeed = 2.0f; /**< The rotation speed of the camera. */
        float fovY = 45.0f; /**< The vertical field of view angle in degrees. */
        float aspectRatio = 16.0f / 9.0f; /**< The aspect ratio of the camera. */
        float nearClip = 0.1f; /**< The near clipping plane distance. */
        float farClip = 100.f; /**< The far clipping plane distance. */
    };

    /**
    * @class CameraControllerEuler
    * @brief Euler angle-based FPS camera controller.
    * This class provides a camera controller using Euler angles for the first-person view.
    * It allows controlling camera movement and rotation based on user input.
    */
    class CameraControllerEuler : public CameraController
    {
    public:
        /**
        * @brief Constructor for CameraControllerEuler.
        * @param props Configuration properties for the camera controller.
        */
        CameraControllerEuler(const FPSEulerCameraProps& props);

        /**
        * @brief Callback for updating the camera controller.
        * @param timestep The time elapsed since the last update.
        */
        void onUpdate(float timestep) override;

    private:
        FPSEulerCameraProps m_props; /**< Configuration properties for the camera controller. */
        glm::mat4 m_model; /**< The model matrix for the camera. */
        glm::vec3 m_forward; /**< The forward vector of the camera. */
        glm::vec3 m_up; /**< The up vector of the camera. */
        glm::vec3 m_right; /**< The right vector of the camera. */
        glm::vec2 m_lastMousePosition; /**< The last recorded mouse position. */
    };

}
