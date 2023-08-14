/*****************************************************************//**
@file   bufferLayout.h
@brief  The IndexBuffer class provides an abstract interface for index buffers used in graphics rendering.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <cstdint>

namespace Engine
{
    /**
    * @class IndexBuffer
    * @brief Abstract base class for index buffers used in graphics rendering.
    */
    class IndexBuffer
    {
    public:
        /** @brief Virtual destructor for IndexBuffer.*/
        virtual ~IndexBuffer() = default;

        /**
        * @brief Get the render ID of the index buffer.
        * @return The render ID.
        */
        virtual inline uint32_t getRenderID() const = 0;

        /**
        * @brief Get the count of indices in the index buffer.
        * @return The count of indices.
        */
        virtual inline uint32_t getCount() const = 0;

        /**
        * @brief Create an instance of an IndexBuffer.
        *
        * This function creates and returns an instance of an IndexBuffer.
        * It takes the indices and their count as parameters.
        *
        * @param indices Pointer to an array of indices.
        * @param count The count of indices in the array.
        * @return A pointer to the created IndexBuffer instance.
        */
        static IndexBuffer* create(uint32_t* indices, uint32_t count);
    };
}