/*****************************************************************//**
@file   renderAPI.h
@brief  The RenderAPI class provides a mechanism to determine the rendering API that is currently being used.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

namespace Engine
{
    /**
    * @class RenderAPI
    * @brief Provides an interface to determine the rendering API in use.
    */
    class RenderAPI
    {
    public:
        /**
        * @enum API
        * @brief Enumerates different rendering APIs.
        */
        enum class API { None = 0, OpenGL = 1, Direct3D = 2, Vulkan = 3 };

        /**
        * @brief Get the current rendering API.
        * @return The API enum value representing the rendering API in use.
        */
        inline static API getAPI() { return s_API; }

    private:
        /**
        * @var s_API
        * @brief The static member variable to store the current rendering API.
        */
        static API s_API;
    };
}