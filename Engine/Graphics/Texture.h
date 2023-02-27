#pragma once

#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        class Texture
        {
        private:
            uint32_t m_TexID;
            std::string m_FilePath;
            uint8_t* m_LocalBuffer;
            int m_Width, m_Height, m_BPP;
        public:
            Texture();
            Texture(const std::string& path);
            ~Texture();

            void Bind(uint32_t slot = 0) const;
            void Unbind() const;

            inline int GetWidth() const { return (m_Width); }
            inline int GetHeigth() const { return (m_Height); }
        };
        
    } // namespace Graphics
} // namespace Orion
