#include <fstream>
#include <sstream>

#include "Shader.h"
#include "Renderer.h"

namespace Orion { 
    namespace Graphics {

        Shader::Shader(const std::string& filepath)
        : m_FilePath(filepath)
        {
            ShaderProgramSource source = ParseShader(filepath);
            m_ShaderID = CreateShader(source.VertexSource, source.FragmentSource);
        }

        Shader::~Shader()
        {
            GLCall(glDeleteProgram(m_ShaderID));
        }

        void Shader::Enable() const
        {
            GLCall(glUseProgram(m_ShaderID));
        }

        void Shader::Disable() const
        {
            GLCall(glUseProgram(0));
        }

        void Shader::SetUniform1i(const std::string &name, int value) const
        {
            GLCall(glUniform1i(GetUniformLocation(name), value));
        }

        void Shader::SetUniform1f(const std::string &name, float value) const
        {
            GLCall(glUniform1f(GetUniformLocation(name), value));
        }

        void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const
        {
            GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
        }

        void Shader::SetUniformMat4f(const std::string &name, const glm::mat4 &ortho) const
        {
            GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &ortho[0][0]));
        }

        ShaderProgramSource Shader::ParseShader(const std::string &filepath)
        {
            std::ifstream stream(filepath);

            enum class ShaderType
            {
                NONE = -1, VERTEX = 0, FRAGMENT = 1
            };

            ShaderType type = ShaderType::NONE;

            std::string line;
            std::stringstream ss[2];
            while (getline(stream, line))
            {
                if (line.find("#shader") != std::string::npos)
                {
                    if (line.find("vertex") != std::string::npos)
                    {
                        type = ShaderType::VERTEX;
                    }
                    else if (line.find("fragment") != std::string::npos)
                    {
                        type = ShaderType::FRAGMENT;
                    }
                }
                else
                {
                    ss[(int)type] << line << '\n';
                }
            }
            return { ss[0].str(), ss[1].str() };
        }

        uint32_t Shader::CompileShader(uint32_t type, const std::string& source)
        {
            GLCall(uint32_t shader = glCreateShader(type));
            const char* src = source.c_str();
            GLCall(glShaderSource(shader, 1, &src, nullptr));
            GLCall(glCompileShader(shader));
            
            // CHECK COMPILATION
            int result;
            char message[512];
            GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
            if (!result)
            {
                GLCall(glGetShaderInfoLog(shader, 512, nullptr, message));
                std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ") << "shader: " << std::endl;
                std::cout << message << std::endl;
                return (0);
            }
            return (shader);
        }

        uint32_t Shader::CreateShader(const std::string &vSource, const std::string &fSource)
        {
            GLCall(uint32_t program = glCreateProgram());
            uint32_t vertexShader = CompileShader(GL_VERTEX_SHADER, vSource);
            uint32_t fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fSource);

            GLCall(glAttachShader(program, vertexShader));
            GLCall(glAttachShader(program, fragmentShader));
            GLCall(glLinkProgram(program));

            // CHECK LINKAGE
            int result;
            char message[512];
            GLCall(glGetProgramiv(program, GL_LINK_STATUS, &result));
            if (!result)
            {
                GLCall(glGetProgramInfoLog(program, 512, nullptr, message));
                std::cout << "Failed to link shader program!: " << message << std::endl;
                return (0);
            }

            GLCall(glValidateProgram(program));
            GLCall(glDeleteShader(vertexShader));
            GLCall(glDeleteShader(fragmentShader));
            return (program);
        }

        uint32_t Shader::GetUniformLocation(const std::string &name) const
        {
            if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
                 return (m_UniformLocationCache[name]);

            GLCall(int location = glGetUniformLocation(m_ShaderID, name.c_str()));
            if (location == -1)
                std::cout << "Warning: uniform " << name << " not found!" << std::endl;
            
            m_UniformLocationCache[name] = location;
            return (location);
        }

    } // namespace Graphics
} // namespace Orion 
