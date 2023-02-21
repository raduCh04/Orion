#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Graphics/Window.h"

int main(int, const char **)
{
    #if defined(__linux__)
    using namespace Orion::Graphics;
    Window window("Window", 800, 600);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //Main loop
    while (!window.Closed())
    {
        window.Clear();
        window.Update();
    }
    
    return (EXIT_SUCCESS);
    #elif defined(_WIN32)
    std::cout << "Supports only linux" << std::endl;
    #endif
}
