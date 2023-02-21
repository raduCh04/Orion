#include "Shader.h"
#include "Renderer.h"

namespace Orion { 
    namespace Graphics {

        Shader::Shader(const std::string& vSource, const std::string& fSource)
        : m_VertexShaderPath(vSource), m_FragmentShaderPath(fSource)
        {
            m_ShaderID = CreateShader(m_VertexShaderPath, m_FragmentShaderPath);
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

        void Shader::SetUniform1i(const std::string &name, int value)
        {
            GLCall(glUniform1i(GetUniformLocation(name), value));
        }

        void Shader::SetUniform1f(const std::string &name, float value)
        {
            GLCall(glUniform1f(GetUniformLocation(name), value));
        }

        void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
        {
            GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
        }

        uint32_t Shader::ParseShader(uint32_t type, const std::string &source)
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
                std::cout << "Error compiling " << 
                ((type == GL_VERTEX_SHADER) ? "Vertex Shader: " : "Fragment shader: ") 
                << message << std::endl;

                return (0);
            }
            std::cout << ((type == GL_VERTEX_SHADER) ? "Vertex Shader: " : "Fragment shader: ") <<
            "compilation succeded!" << std::endl;
            return (shader);
        }

        uint32_t Shader::CreateShader(const std::string &vSource, const std::string &fSource)
        {
            GLCall(uint32_t program = glCreateProgram());
            uint32_t vertexShader = ParseShader(GL_VERTEX_SHADER, read_file(vSource));
            uint32_t fragmentShader = ParseShader(GL_FRAGMENT_SHADER, read_file(fSource));

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

        uint32_t Shader::GetUniformLocation(const std::string &name)
        {
            if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
                return (m_UniformLocationCache[name]);

            GLCall(int location = glGetUniformLocation(m_ShaderID, name.c_str()));
            if (location == -1)
                std::cout << "Warning: uniform " << name << " not found!" << std::endl;
            
            m_UniformLocationCache[name] = location;
            std::cout << location << std::endl;
            return (location);
        }

    } // namespace Graphics
} // namespace Orion 
