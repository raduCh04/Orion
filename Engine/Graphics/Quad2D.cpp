#include "Quad2D.h"
#include "VertexBufferLayout.h"

namespace Orion {
    namespace Graphics {
        
        Quad2D::Quad2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader)
            : m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
            {
                m_VertexArray = new VertexArray();
                uint32_t indices[] = {
                    0, 1, 2, 2, 3, 0
                };

                float vertices[] = {
                    0, 0, 0,
                    0, m_Size.y, 0,
                    m_Size.x, m_Size.y, 0,
                    m_Size.x, 0, 0
                };

                float colors[] = {
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                };
                m_BufferLayout = new VertexBufferLayout();
                m_BufferLayout->Push(GL_FLOAT, 3);
                m_VertexArray->AddBuffer(*(new VertexBuffer(vertices, sizeof(vertices))), *m_BufferLayout);
                m_IndexBuffer = new IndexBuffer(indices, 6);
            }

            Quad2D::~Quad2D()
            {
                delete m_VertexArray;
                delete m_BufferLayout;
                delete m_IndexBuffer;
            }
            
    } // namespace Graphics
} // namespace Orion
