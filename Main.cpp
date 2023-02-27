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
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

int main(int, const char **)
{
    using namespace Orion;
    using namespace Graphics;

    Window window("Window", 1280, 720);
    window.SetColor(0.5f, 0.3f, 0.2f, 1.0f);

    Renderer renderer(window);

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window.GetWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 130");
    ImGui::StyleColorsDark();

    renderer.EnableBlending();
    renderer.EnableDepthTest();

    Shader shaderQuad("..//Assets//Shaders//Basic2D.shader");
    Shader shaderQuad3D("..//Assets//Shaders//Basic3D.shader");
    Texture tex("..//Assets//Textures//tile1.png");

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

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (!window.Closed())
    {
        window.Clear();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        glm::vec4 quadColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);

        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);           // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // E      // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::SliderFloat("X Position", &cubePositions[0].x, -3.0f, 3.0f);
        ImGui::SliderFloat("Y Position", &cubePositions[0].y, -3.0f, 3.0f);
        ImGui::SliderFloat("Z Position", &cubePositions[0].z, -3.0f, 3.0f);

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
        Quad3D quad3 = Quad3D(cubePositions[0], glm::vec3(0.5f, 0.5f, 0.5f), shaderQuad3D, quadColor, &tex);
        renderer.Draw3D(quad3);
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        window.Update();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    return (EXIT_SUCCESS);
}