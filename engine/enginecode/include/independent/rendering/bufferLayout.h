/*****************************************************************//**
@file   bufferLayout.h
@brief  The BufferLayout class represents the layout of a buffer, containing a collection of BufferElement objects along with the stride value for the layout.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <vector>
#include "shaderDataType.h"

namespace Engine
{
    /**
    * @class BufferElement
    * @brief Represents an element in a buffer layout.
    * The BufferElement class represents an element in a buffer layout, containing information
    * about the data type, size, offset, and normalization of the element.
    */
    class BufferElement
    {
    public:
        ShaderDataType m_dataType; /**< The data type of the element. */
        uint32_t m_size; /**< The size of the element in bytes. */
        uint32_t m_offset; /**< The offset of the element within the buffer. */
        bool m_normalised; /**< Flag indicating whether the element's values are normalized. */

        /** @brief Default constructor for BufferElement.*/
        BufferElement() {}

        /**
        * @brief Constructor for BufferElement.
        * @param dataType The data type of the element.
        * @param normalised Flag indicating whether the element's values are normalized.
        */
        BufferElement(ShaderDataType dataType, bool normalised = false) :
            m_dataType(dataType),
            m_size(SDT::size(dataType)),
            m_offset(0),
            m_normalised(normalised)
        {}
    };

    /**
    * @class BufferLayout
    * @brief Represents the layout of a buffer containing multiple elements.
    */
    class BufferLayout
    {
    public:
        /**
         * @brief Default constructor for BufferLayout.
         */
        BufferLayout() {};

        /**
        * @brief Constructor for BufferLayout.
        * @param elements The initializer list of BufferElement objects.
        * @param stride The stride value for the layout.
        */
        BufferLayout(const std::initializer_list<BufferElement>& elements, uint32_t stride = 0)
            : m_elements(elements), m_stride(stride) {
            calcStrideAndOffset();
        }

        /**
        * @brief Get the stride value of the buffer layout.
        * @return The stride value.
        */
        inline uint32_t getStride() const { return m_stride; }

        /**
        * @brief Add a new BufferElement to the layout.
        * @param element The BufferElement to be added.
        */
        void addElement(BufferElement element);

        // Iterators for BufferElement collection
        inline std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
        inline std::vector<BufferElement>::iterator end() { return m_elements.end(); }
        inline std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
        inline std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }

    private:
        std::vector<BufferElement> m_elements; /**< Collection of BufferElement objects in the layout. */
        uint32_t m_stride; /**< Stride value for the buffer layout. */

        /** @brief Calculate the stride and offset values for the elements in the layout.*/
        void calcStrideAndOffset();
    };
}