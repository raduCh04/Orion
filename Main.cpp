#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Graphics/Window.h"
#include "Engine/Graphics/Renderer.h"
#include "Engine/Graphics/VertexBufferLayout.h"
#include "Engine/Graphics/Shader.h"
#include "Engine/Graphics/VertexBuffer.h"
#include "Engine/Graphics/IndexBuffer.h"
#include "Engine/Graphics/VertexArray.h"
#include "Engine/Graphics/Texture.h"

int main(int, const char **)
{
    using namespace Orion;
    using namespace Graphics;

    Window window("Window", 800, 600);
    window.SetColor(.5f, .3f, .8f, 1.0f);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,  // 0
        0.5f, -0.5f, 1.0f, 0.0f,   // 1
         0.5f,  0.5f, 1.0f, 1.0f,  // 2
         -0.5f,  0.5f, 0.0f, 1.0f // 3
    };

    uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    Renderer renderer;
    Texture texture("../Assets/Textures/tile1.png");
    texture.Bind();

    VertexArray va;
    VertexBufferLayout layout;
    layout.Push(GL_FLOAT, 2);
    layout.Push(GL_FLOAT, 2);
    VertexBuffer vb(vertices, sizeof(vertices));
    va.AddBuffer(vb, layout);
    IndexBuffer ib(indices, 6);
    Shader shader("../Assets/Shaders/Vertex.shader", "../Assets/Shaders/Fragment.shader");
    shader.Enable();
    shader.SetUniform1i("u_Texture", 0);

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    //Main loop
    while (!window.Closed())
    {
        window.Clear();
        renderer.Draw(va, ib, shader);
        window.Update();
    }
    
    return (EXIT_SUCCESS);
}
