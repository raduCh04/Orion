#pragma once

#include <string>
#include <string.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Orion {
    namespace Graphics{

        #define MAX_KEYS 1024
        #define MAX_BUTTONS 32

        class Window
        {
        private:
            std::string m_Title;
            uint32_t m_Width, m_Height;
            GLFWwindow* m_Window;
            bool m_Keys[MAX_KEYS];
            bool m_MouseButtons[MAX_BUTTONS];
            float m_MouseX, m_MouseY;
        public:
            Window(const std::string& title, uint32_t width, uint32_t height);
            ~Window();

            bool Init();
            bool Closed() const;
            void Clear() const;
            void Update();
            void GetMouseButton(float& x, float& y) const;

            bool IsKeyPressed(uint32_t key) const;
            bool IsMouseButtonPressed(uint32_t button) const;


            inline uint32_t GetWidth() const { return (m_Width); }
            inline uint32_t GetHeigth() const { return (m_Height); }
        private:
            friend void window_resize_callback(GLFWwindow* window, int width, int height);
            friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
            friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        }; // class Window
    } //namespace Graphics
} // namespace Orion