#include "IndexBuffer.h"
#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        IndexBuffer::IndexBuffer(const uint32_t *data, uint32_t count)
        : m_Count(count), m_IBufferID(0)
        {
            GLCall(glGenBuffers(1, &m_IBufferID));
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBufferID));
            GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
        }

        IndexBuffer::~IndexBuffer()
        {
            GLCall(glDeleteBuffers(1, &m_IBufferID));
        }

        void IndexBuffer::Bind() const
        {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBufferID));
        }

        void IndexBuffer::Unbind() const
        {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
        }

    } // namespace Graphics
} // namespace Orion
