#include "VertexBuffer.h"
#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        VertexBuffer::VertexBuffer(const void* data, uint32_t size)
        {
            GLCall(glGenBuffers(1, &m_BufferID));
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_BufferID));
            GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
        }

        VertexBuffer::~VertexBuffer()
        {
            GLCall(glDeleteBuffers(1, &m_BufferID));
        }

        void VertexBuffer::Bind() const
        {
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_BufferID));
        }

        void VertexBuffer::Unbind() const
        {
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
        }

    } // namespace Graphics
} // namespace Orion