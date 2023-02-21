#pragma once

#include <iostream>
#include <glad/glad.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
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
        
        class Renderer
        {
        private:
        public:
            void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
        };
    } // namespace Graphics
} // namespace Orion