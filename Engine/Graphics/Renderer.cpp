#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        #define ASSERT(x) if (!(x)) raise(SIGTRAP)
        #define GLCall(x) GLClearError();\
            x;\
            ASSERT(GLCheckError(#x, __FILE__, __LINE__))

        void GLClearError()
        {
            while(glGetError() != GL_NO_ERROR);
        }

        bool GLCheckError(const char* function, const char* file, int line)
        {
            while (GLenum error = glGetError())
            {
                std::cout << "[OpenGL Error] (" << error << ")\nFunction: " 
                << function << "\nFile: " << file << "\nLine: " << line << std::endl;
                return (false);
            }
            return (true);
        }

        void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const
        {
            shader.Enable();
            va.Bind();
            ib.Bind();
            GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
        }

    } // namespace Graphics
} // namespace Orion