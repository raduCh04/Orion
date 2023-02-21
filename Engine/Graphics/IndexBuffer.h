#pragma once

#include <iostream>

namespace Orion {
    namespace Graphics {

        class IndexBuffer
        {
        private:
            uint32_t m_IBufferID;
            uint32_t m_Count;
        public:
            IndexBuffer(const uint32_t* data, uint32_t count);
            ~IndexBuffer();

            void Bind() const;
            void Unbind() const;

            inline uint32_t GetCount() const { return (m_Count); }
        }; // class IndexBuffer

    } // namespace Graphics
} // namespace Orion