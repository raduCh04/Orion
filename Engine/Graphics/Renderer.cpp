#include "Renderer.h"
#include "Quad3D.h"

namespace Orion {
    namespace Graphics {

        #if defined(__linux__)
        #define ASSERT(x) if (!(x)) raise(SIGTRAP)
        #endif
        #if defined(_WIN32)
        #define ASSERT(x) if (!(x)) __debugbreak()
        #endif
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
            va.Bind();
            ib.Bind();
            shader.Enable();
            GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
        }

        void Renderer::Draw2D(const Quad2D &renderable) const
        {
            renderable.GetVAO()->Bind();
            renderable.GetIBO()->Bind();
            renderable.GetShader().Enable();
            renderable.GetShader().SetUniformMat4f("proj_matrix", glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f));

            glm::mat4 mat = glm::mat4(1.0f);
            mat = glm::translate(mat, renderable.GetPosition());

            renderable.GetShader().SetUniformMat4f("u_Matrix", mat);
            renderable.GetShader().SetUniform4f("u_Color", renderable.GetColor().x, renderable.GetColor().y, renderable.GetColor().z, renderable.GetColor().w);
            GLCall(glDrawElements(GL_TRIANGLES, renderable.GetIBO()->GetCount(), GL_UNSIGNED_INT, 0));
        }

        Renderer::Renderer(Window &window)
            : m_Window(window)
        {
        }

        void Renderer::Draw3D(const Quad3D &quad) const
        {
            quad.GetVAO()->Bind();
            quad.GetShader().Enable();
            
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 projection = glm::mat4(1.0f);

            model = glm::translate(model, quad.GetPosition());
            model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
            projection = glm::perspective(glm::radians(45.0f), (((float)m_Window.GetWidth() / (float)m_Window.GetHeigth())), 0.1f, 100.0f);

            quad.GetShader().SetUniformMat4f("u_Model", model);
            quad.GetShader().SetUniformMat4f("u_View", view);
            quad.GetShader().SetUniformMat4f("u_Projection", projection);
            quad.GetShader().SetUniform4f("u_Color", quad.GetColor().x, quad.GetColor().y, quad.GetColor().z, quad.GetColor().w);
            quad.GetShader().SetUniform4f("lightColor", 1.0f, 1.0f, 1.0f, 1.0f);
            if (quad.GetTexture() != nullptr)
            {
                quad.GetTexture()->Bind(0);
            }

            GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
        }

        void Renderer::EnableBlending() const
        {
            GLCall(glEnable(GL_BLEND));
            GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        }

        void Renderer::EnableDepthTest() const
        {
            GLCall(glEnable(GL_DEPTH_TEST));
        }

    } // namespace Graphics
} // namespace Orion