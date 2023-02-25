#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Window.h"
#include "Quad2D.h"
#include "Quad3D.h"
#include "Shader.h"

#if defined(__linux__)
    #include <signal.h>
#endif
namespace Orion { 
    namespace Graphics {

        void GLClearError();
        bool GLCheckError(const char* function, const char* file, int line);

        #define ASSERT(x) if (!(x)) raise(SIGTRAP)
        #define GLCall(x) GLClearError();\
            x;\
            ASSERT(GLCheckError(#x, __FILE__, __LINE__))
        class Quad3D;
        class Renderer
        {
        private:
            Window& m_Window;
        public:
            Renderer(Window& window);
            void Draw3D(const Quad3D& quad) const;
            void Draw2D(const Quad2D& quad) const;
            void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
            void EnableBlending() const;
            void EnableDepthTest() const;
        };
    } // namespace Graphics
} // namespace Orion