#include "Window.h"
#include "Renderer.h"

namespace Orion {
    namespace Graphics {

        void window_resize_callback(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->m_Keys[key] = action != GLFW_RELEASE;
        }

        void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
        {
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->m_MouseButtons[button] = action != GLFW_RELEASE;
        }

        void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
        {
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->m_MouseX = xpos;
            win->m_MouseY = ypos;
        }

        Window::Window(const std::string &title, uint32_t width, uint32_t height)
        : m_Title(title), m_Width(width), m_Height(height), m_MouseX(0), m_MouseY(0)
        {
            memset(m_Keys, false, MAX_KEYS);
            memset(m_MouseButtons, false, MAX_BUTTONS);

            if (!Init())
                glfwTerminate();
        }

        Window::~Window()
        {
            glfwTerminate();
        }

        bool Window::Init()
        {
            if (!glfwInit())
            {
                std::cout << "ERROR: Failed to init GLFW!" << std::endl;
                return (false);
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

            if (!m_Window)
            {
                std::cout << "ERROR: Failed to create Window!" << std::endl;
                return (false);
            }

            glfwMakeContextCurrent(m_Window);
            glfwSwapInterval(1);
            glfwSetWindowUserPointer(m_Window, this);
            glfwSetFramebufferSizeCallback(m_Window, window_resize_callback);
            glfwSetKeyCallback(m_Window, key_callback);
            glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
            glfwSetCursorPosCallback(m_Window, cursor_position_callback);

            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                std::cout << "ERROR: Failed to init GLAD!" << std::endl;

            return (true);
        }

        bool Window::Closed() const
        {
            return (glfwWindowShouldClose(m_Window) == 1);
        }

        void Window::Clear() const
        {
            GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
        }

        void Window::Update()
        {
            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }

        void Window::GetMouseButton(float &x, float &y) const
        {
            x = m_MouseX;
            y = m_MouseY;
        }

        void Window::SetColor(float r, float g, float b, float a) const
        {
            GLCall(glClearColor(r, g, b, a));
        }

        bool Window::IsKeyPressed(uint32_t key) const
        {
            if (key < MAX_KEYS)
            {
                return (m_Keys[key]);
            }
            return (false);
        }
        bool Window::IsMouseButtonPressed(uint32_t button) const
        {
            if (button < MAX_BUTTONS)
            {
                return (m_MouseButtons[button]);
            }
            return (false);
        }
        
    } //namespace Graphics
} //namespace Orion