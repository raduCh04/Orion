#include "Quad3D.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

namespace Orion {
    namespace Graphics {
        
        Quad3D::Quad3D(glm::vec3 position, glm::vec3 size, Shader& shader, glm::vec4 color, Texture* texture)
            : m_Position(position), m_Size(size), m_Color(color), m_Shader(shader), m_Texture(texture)
            {
                m_VertexArray = new VertexArray();

                float vertices[] = {
                    -size.x, -size.y, -size.z, 0.0f, 0.0f,
                     size.x, -size.y, -size.z, 1.0f, 0.0f,
                     size.x,  size.y, -size.z, 1.0f, 1.0f,
                     size.x,  size.y, -size.z, 1.0f, 1.0f,
                    -size.x,  size.y, -size.z, 0.0f, 1.0f,
                    -size.x, -size.y, -size.z, 0.0f, 0.0f,

                    -size.x, -size.y,  size.z, 0.0f, 0.0f,
                     size.x, -size.y,  size.z, 1.0f, 0.0f,
                     size.x,  size.y,  size.z, 1.0f, 1.0f,
                     size.x,  size.y,  size.z, 1.0f, 1.0f,
                    -size.x,  size.y,  size.z, 0.0f, 1.0f,
                    -size.x, -size.y,  size.z, 0.0f, 0.0f,

                    -size.x,  size.y,  size.z, 0.0f, 0.0f,
                    -size.x,  size.y, -size.z, 1.0f, 0.0f,
                    -size.x, -size.y, -size.z, 1.0f, 1.0f,
                    -size.x, -size.y, -size.z, 1.0f, 1.0f,
                    -size.x, -size.y,  size.z, 0.0f, 1.0f,
                    -size.x,  size.y,  size.z, 0.0f, 0.0f,

                     size.x,  size.y,  size.z, 0.0f, 0.0f,
                     size.x,  size.y, -size.z, 1.0f, 0.0f,
                     size.x, -size.y, -size.z, 1.0f, 1.0f,
                     size.x, -size.y, -size.z, 1.0f, 1.0f,
                     size.x, -size.y,  size.z, 0.0f, 1.0f,
                     size.x,  size.y,  size.z, 0.0f, 0.0f,

                    -size.x, -size.y, -size.z, 0.0f, 0.0f,
                     size.x, -size.y, -size.z, 1.0f, 0.0f,
                     size.x, -size.y,  size.z, 1.0f, 1.0f,
                     size.x, -size.y,  size.z, 1.0f, 1.0f,
                    -size.x, -size.y,  size.z, 0.0f, 1.0f,
                    -size.x, -size.y, -size.z, 0.0f, 0.0f,

                    -size.x,  size.y, -size.z, 0.0f, 0.0f,
                     size.x,  size.y, -size.z, 1.0f, 0.0f,
                     size.x,  size.y,  size.z, 1.0f, 1.0f,
                     size.x,  size.y,  size.z, 1.0f, 1.0f,
                    -size.x,  size.y,  size.z, 0.0f, 1.0f,
                    -size.x,  size.y, -size.z, 0.0f, 0.0f,
                };

                float colors[] = {
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                };

                uint32_t indices[] = {
                    0, 1, 2, 1, 2, 3
                };
                m_BufferLayout = new VertexBufferLayout();
                m_BufferLayout->Push(GL_FLOAT, 3);
                m_BufferLayout->Push(GL_FLOAT, 2);
                m_VertexArray->AddBuffer(*(new VertexBuffer(vertices, sizeof(vertices))), *m_BufferLayout);
                //m_IndexBuffer = new IndexBuffer(indices, 36);
            }

            Quad3D::~Quad3D()
            {
                delete m_VertexArray;
                delete m_BufferLayout;
                //delete m_IndexBuffer;
            }
            
    } // namespace Graphics
} // namespace Orion
