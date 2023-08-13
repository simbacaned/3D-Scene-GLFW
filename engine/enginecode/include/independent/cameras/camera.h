/*****************************************************************//**
@file   camera.h
@brief  Basic camera base class

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "core/application.h"

class Camera
{
public:
	glm::mat4 view;
	glm::mat4 projection;
	void updateView(const glm::mat4& transform)
	{
		view = glm::inverse(transform);
	}
};

