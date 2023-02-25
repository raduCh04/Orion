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
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

int main(int, const char **)
{
    using namespace Orion;
    using namespace Graphics;

    Window window("Window", 800, 600);
    window.SetColor(0.5f, 0.3f, 0.2f, 1.0f);

    Renderer renderer(window);
    renderer.EnableBlending();
    renderer.EnableDepthTest();

    Shader shaderQuad("../Assets/Shaders/Basic.shader");
    Shader shaderQuad3D("../Assets/Shaders/3DShader.shader");
    Texture tex("../Assets/Textures/Andrea.jpg");

    glm::vec3 position = glm::vec3(0, 0, 0);

    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f), 
        glm::vec3( 2.0f,  5.0f, -15.0f), 
        glm::vec3(-1.5f, -2.2f, -2.5f),  
        glm::vec3(-3.8f, -2.0f, -12.3f),  
        glm::vec3( 2.4f, -0.4f, -3.5f),  
        glm::vec3(-1.7f,  3.0f, -7.5f),  
        glm::vec3( 1.3f, -2.0f, -2.5f),  
        glm::vec3( 1.5f,  2.0f, -2.5f), 
        glm::vec3( 1.5f,  0.2f, -1.5f), 
        glm::vec3(-1.3f,  1.0f, -1.5f)  
    };
    int i = 0;
    while (!window.Closed())
    {

        window.Clear();
        Quad3D quad3 = Quad3D(cubePositions[i], glm::vec2(0.5f, 0.5f), glm::vec4(.3f, 0.2f, 0.6f, 1.0f), shaderQuad3D, tex);
        renderer.Draw3D(quad3);
        //renderer.Draw3D(quad3);
        window.Update();
    }
    
    return (EXIT_SUCCESS);
}