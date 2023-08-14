/*****************************************************************//**
@file   graphicsContext.h
@brief  The GraphicsContext class serves as an abstract interface for managing graphics contexts in different rendering environments.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

/**
* @class GraphicsContext
* @brief Abstract base class for graphics context interfaces.
*/
class GraphicsContext
{
public: 
    /** @brief Initialize the graphics context.*/
    virtual void init() = 0;

    /** @brief Swap the front and back buffers.*/
    virtual void swapBuffers() = 0;
};
