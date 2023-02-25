#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace Orion {
    namespace Graphics {
        
        class VertexBufferLayout;

        class Quad2D
        {   
        protected:
            glm::vec3 m_Position;
            glm::vec2 m_Size;
            glm::vec4 m_Color;

            VertexArray *m_VertexArray;
            IndexBuffer *m_IndexBuffer;
            VertexBufferLayout *m_BufferLayout;
            Shader& m_Shader;
        public:
            Quad2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader);
            ~Quad2D();
        public:

            inline const glm::vec3 GetPosition() const { return (m_Position); }
            inline const glm::vec2 GetSize() const { return (m_Size); }
            inline const glm::vec4 GetColor() const { return (m_Color); }

            inline const VertexArray* GetVAO() const { return (m_VertexArray); };
            inline const IndexBuffer* GetIBO() const { return (m_IndexBuffer); };
            inline const Shader& GetShader() const { return (m_Shader); }
        };

    } // namespace Graphics  
} // namespace Orion
