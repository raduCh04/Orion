#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <glad/glad.h>
#include "../Utils.h"

namespace Orion {
    namespace Graphics
    {
        class Shader
        {
        private:
            uint32_t m_ShaderID;
            std::unordered_map<std::string, int> m_UniformLocationCache; 
            std::string m_VertexShaderPath;
            std::string m_FragmentShaderPath;
        public:
            Shader(const std::string& vSource, const std::string& fSource);
            ~Shader();
            void Enable() const;
            void Disable() const;
            void SetUniform1i(const std::string& name, int value);
            void SetUniform1f(const std::string& name, float value);
            void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
        private:
            uint32_t ParseShader(uint32_t type, const std::string& source);
            uint32_t CreateShader(const std::string& vSource, const std::string& fSource);
            uint32_t GetUniformLocation(const std::string& name);
        }; // class Shader

    } // namespace Graphics
} // namespace Orion
