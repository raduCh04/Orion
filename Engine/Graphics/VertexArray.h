#pragma once

#include "VertexBuffer.h"


namespace Orion {
    namespace Graphics {

        class VertexBufferLayout;
        
        class VertexArray
        {
        private:
            uint32_t m_ArrayID;
        public:
            VertexArray();
            ~VertexArray();

            void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

            void Bind() const;
            void Unbind() const;
        }; // class VertexArray

    } // namespace Graphics
} // namespace Orion