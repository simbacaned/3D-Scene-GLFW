/*****************************************************************//**
@file   shaderDataType.h
@brief  The RenderAPI class provides a mechanism to determine the rendering API that is currently being used.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <cstdint>

namespace Engine
{
    /**
    * @enum ShaderDataType
    * @brief Enumerates different shader data types.
    */
    enum class ShaderDataType
    {
        None = 0, ///< No data type.
        Float,    ///< Single-precision floating point.
        Float2,   ///< Two-component floating point.
        Float3,   ///< Three-component floating point.
        Float4,   ///< Four-component floating point.
        Short,    ///< Short integer.
        Short2,   ///< Two-component short integer.
        Short3,   ///< Three-component short integer.
        Short4    ///< Four-component short integer.
    };

    /**
    * @namespace SDT
    * @brief The namespace that provides utility functions related to ShaderDataType.
    */
    namespace SDT
    {
        /**
        * @brief Get the size (in bytes) of a ShaderDataType.
        * @param type The ShaderDataType to get the size for.
        * @return The size in bytes of the specified ShaderDataType.
        */
        static uint32_t size(ShaderDataType type)
        {
            switch (type)
            {
            case ShaderDataType::Float:  return 4;
            case ShaderDataType::Float2: return 4 * 2;
            case ShaderDataType::Float3: return 4 * 3;
            case ShaderDataType::Float4: return 4 * 4;
            case ShaderDataType::Short:  return 2;
            case ShaderDataType::Short2: return 2 * 2;
            case ShaderDataType::Short3: return 2 * 3;
            case ShaderDataType::Short4: return 2 * 4;
            default: return 0;
            }
        }

        /**
        * @brief Get the component count of a ShaderDataType.
        * @param type The ShaderDataType to get the component count for.
        * @return The number of components in the specified ShaderDataType.
        */
        static uint32_t componentCount(ShaderDataType type)
        {
            switch (type)
            {
            case ShaderDataType::Float:  return 1;
            case ShaderDataType::Float2: return 2;
            case ShaderDataType::Float3: return 3;
            case ShaderDataType::Float4: return 4;
            case ShaderDataType::Short:  return 1;
            case ShaderDataType::Short2: return 2;
            case ShaderDataType::Short3: return 3;
            case ShaderDataType::Short4: return 4;
            default: return 0;
            }
        }
    }
}