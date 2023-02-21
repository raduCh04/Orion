#pragma once

#include <iostream>

namespace Orion {
    namespace Graphics {

        class VertexBuffer
        {
        private:
            uint32_t m_BufferID;
        public:
            VertexBuffer(const void* data, uint32_t size);
            ~VertexBuffer();

            void Bind() const;
            void Unbind() const;
        }; // class VertexBuffer

    } // namespace Graphics
} // namespace Orion