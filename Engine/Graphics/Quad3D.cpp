#include "Quad3D.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

namespace Orion {
    namespace Graphics {
        
        Quad3D::Quad3D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader, Texture& texture)
            : m_Position(position), m_Size(size), m_Color(color), m_Shader(shader), m_Texture(texture)
            {
                m_VertexArray = new VertexArray();

                float vertices[] = {
                    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
                     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
                     0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
                     0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
                    -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
                    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

                    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
                     0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
                     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
                     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
                    -0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
                    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,

                    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
                    -0.5f,  0.5f, -0.5f, 1.0f, 0.0f,
                    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
                    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
                    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f,
                    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,

                     0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
                     0.5f,  0.5f, -0.5f, 1.0f, 0.0f,
                     0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
                     0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
                     0.5f, -0.5f,  0.5f, 0.0f, 1.0f,
                     0.5f,  0.5f,  0.5f, 0.0f, 0.0f,

                    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
                     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
                     0.5f, -0.5f,  0.5f, 1.0f, 1.0f,
                     0.5f, -0.5f,  0.5f, 1.0f, 1.0f,
                    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f,
                    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

                    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f,
                     0.5f,  0.5f, -0.5f, 1.0f, 0.0f,
                     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
                     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
                    -0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
                    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f,
                };

                float colors[] = {
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                };
                m_BufferLayout = new VertexBufferLayout();
                m_BufferLayout->Push(GL_FLOAT, 3);
                m_BufferLayout->Push(GL_FLOAT, 2);
                m_VertexArray->AddBuffer(*(new VertexBuffer(vertices, sizeof(vertices))), *m_BufferLayout);
                //m_IndexBuffer = new IndexBuffer(indices, 6);
            }

            Quad3D::~Quad3D()
            {
                delete m_VertexArray;
                delete m_BufferLayout;
                //delete m_IndexBuffer;
            }
            
    } // namespace Graphics
} // namespace Orion
