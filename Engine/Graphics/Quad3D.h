#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"
#include "Texture.h"
#include "Shader.h"

namespace Orion {
    namespace Graphics {
        
        class VertexBufferLayout;
        class Texture;
        class Quad3D
        {   
        private:
            glm::vec3 m_Position;
            glm::vec3 m_Size;
            glm::vec4 m_Color;

            VertexArray *m_VertexArray;
            //IndexBuffer *m_IndexBuffer;
            VertexBufferLayout *m_BufferLayout;
            Texture* m_Texture;
            Shader& m_Shader;
        public:
            Quad3D(glm::vec3 position, glm::vec3 size, Shader& shader, glm::vec4 color = glm::vec4(0), Texture* texture = nullptr);
            ~Quad3D();
        public:

            inline const glm::vec3 GetPosition() const { return (m_Position); }
            inline const glm::vec3 GetSize() const { return (m_Size); }
            inline const glm::vec4 GetColor() const { return (m_Color); }

            inline const VertexArray* GetVAO() const { return (m_VertexArray); };
            //inline const IndexBuffer* GetIBO() const { return (m_IndexBuffer); };
            inline const Shader& GetShader() const { return (m_Shader); }
            inline const Texture* GetTexture() const { return (m_Texture); }
        };

    } // namespace Graphics  
} // namespace Orion
