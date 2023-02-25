#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <glad/glad.h>
#include "glm/gtc/matrix_transform.hpp"

namespace Orion {
    namespace Graphics
    {

        struct ShaderProgramSource
        {
            std::string VertexSource;
            std::string FragmentSource;
        };

        class Shader
        {
        private:
            uint32_t m_ShaderID;
            mutable std::unordered_map<std::string, int> m_UniformLocationCache; 
            std::string m_FilePath;
        public:
            Shader(const std::string& filepath);
            ~Shader();
            void Enable() const;
            void Disable() const;
            
            void SetUniform1i(const std::string& name, int value) const;
            void SetUniform1f(const std::string& name, float value) const;
            void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) const;
            void SetUniformMat4f(const std::string& name, const glm::mat4& ortho) const;
        private:
            ShaderProgramSource ParseShader(const std::string& filepath);
            uint32_t CompileShader(uint32_t type, const std::string& source);
            uint32_t CreateShader(const std::string& vSource, const std::string& fSource);
            uint32_t GetUniformLocation(const std::string& name) const;
        }; // class Shader

    } // namespace Graphics
} // namespace Orion
