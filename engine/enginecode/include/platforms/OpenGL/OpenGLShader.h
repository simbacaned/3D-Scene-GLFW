/*****************************************************************//**
@file   OpenGLShader.h
@brief  This class provides functionality for creating, managing, and uploading OpenGL shaders, both vertex and fragment shaders.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include <glm/glm.hpp>

namespace Engine
{
    /** @brief Class representing an OpenGL shader. */
    class OpenGLShader
    {
    public:
        /**
        * @brief Constructor for OpenGLShader.
        * Constructs an OpenGL shader by compiling and linking the provided
        * vertex and fragment shader files.
        *
        * @param vertexFilepath Path to the vertex shader file.
        * @param fragmentFilepath Path to the fragment shader file.
        */
        OpenGLShader(const char* vertexFilepath, const char* fragmentFilepath);

        /**
        * @brief Constructor for OpenGLShader.
        * Constructs an OpenGL shader by compiling and linking the shader
        * from the provided file.
        *
        * @param filepath Path to the shader file.
        */
        OpenGLShader(const char* filepath);

        /**
        * @brief Destructor for OpenGLShader.
        * Cleans up resources associated with the OpenGL shader.
        */
        ~OpenGLShader();

        /**
        * @brief Get the ID of the OpenGL shader.
        * @return The OpenGL shader ID.
        */
        uint32_t getID() { return m_OpenGL_ID; }

        // Methods for uploading shader uniforms

        void uploadInt(const char* name, int value);
        void uploadFloat(const char* name, float value);
        void uploadFloat2(const char* name, const glm::vec2& value);
        void uploadFloat3(const char* name, const glm::vec3& value);
        void uploadFloat4(const char* name, const glm::vec4& value);
        void uploadMat4(const char* name, const glm::mat4& value);

    private:
        uint32_t m_OpenGL_ID; /**< The OpenGL shader ID. */

        /**
        * @brief Compile and link the shader from source code.
        * This private method compiles and links the shader using the provided
        * vertex and fragment shader source code.
        *
        * @param vertexShaderSrc Vertex shader source code.
        * @param fragmentShaderSrc Fragment shader source code.
        */
        void compileAndLink(const char* vertexShaderSrc, const char* fragmentShaderSrc);
    };
}