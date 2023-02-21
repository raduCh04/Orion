#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        VertexArray::VertexArray()
        {
            GLCall(glGenVertexArrays(1, &m_ArrayID));
        }

        VertexArray::~VertexArray()
        {
            GLCall(glDeleteVertexArrays(1, &m_ArrayID));
        }

        void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
        {
            Bind();
            vb.Bind();
            const auto& elements = layout.GetElements();
            auto offset = 0;
            for (size_t i = 0; i < elements.size(); i++)
            {
                const auto& element = elements[i];
                GLCall(glEnableVertexAttribArray(i));
                GLCall(glVertexAttribPointer(i, element.count, element.type, 
                element.normalized, layout.GetStride(), (void*)offset));
                offset += element.count * VertexBufferElement::GetTypeOfSize(element.type);
            }
        }

        void VertexArray::Bind() const
        {
            GLCall(glBindVertexArray(m_ArrayID));
        }

        void VertexArray::Unbind() const
        {
            GLCall(glBindVertexArray(0));
        }

    } // namespace Graphics
} // namespace Orion