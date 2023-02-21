#pragma once

#include <vector>
#include <glad/glad.h>

#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        struct VertexBufferElement
        {
            uint32_t count;
            uint32_t type;
            uint32_t normalized;

            static uint32_t GetTypeOfSize(uint32_t type)
            {
                switch (type)
                {
                case GL_FLOAT: return (4);
                case GL_UNSIGNED_INT: return (4);
                case GL_BYTE: return (1);
                }
                ASSERT(false);
                return (0);
            }
        }; // struct VertexBufferElement

        class VertexBufferLayout
        {
        private:
            std::vector<VertexBufferElement> m_Elements;
            uint32_t m_Stride;
        public:
            VertexBufferLayout() : m_Stride(0) {}

            void Push(uint32_t type, uint32_t count)
            {
                m_Elements.push_back({ count, type, false });
                m_Stride += VertexBufferElement::GetTypeOfSize(type) * count;
            }

            inline const std::vector<VertexBufferElement>& GetElements() const { return (m_Elements); }
            inline uint32_t GetStride() const { return (m_Stride); }
        }; // class VertexBufferLayout

    } // namespace Graphics
} // namespace Orion