/*****************************************************************//**
@file   camera.h
@brief  This class defines a basic camera with view and projection matrices.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "core/application.h"

 /**
* @class Camera
* @brief Represents a camera in 3D space.
*/
class Camera
{
public:
    /**
    * @brief The view matrix of the camera.
    * The view matrix transforms coordinates from world space to view space.
    */
    glm::mat4 view;

    /**
    * @brief The projection matrix of the camera.
    * The projection matrix transforms coordinates from view space to clip space.
    */
    glm::mat4 projection;

    /**
    * @brief Update the view matrix based on the given transformation.
    * @param transform The transformation matrix to update the view matrix.
    */
    void updateView(const glm::mat4& transform)
    {
        view = glm::inverse(transform);
    }
};

