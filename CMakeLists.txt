project(Orion)

cmake_minimum_required(VERSION 3.20)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Engine/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Graphics/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Maths/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Vendor/stb_image/*.cpp
    )

#add_executable(Orion Main.cpp glad.c ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Graphics/Window.cpp 
#        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Graphics/Renderer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Graphics/Shader.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Utils.cpp ${CMAKE}
#        )

add_executable(Orion Main.cpp glad.c ${SOURCES})
target_include_directories(Orion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Deps/Include/)

if(UNIX)
    target_link_libraries(Orion ${CMAKE_CURRENT_SOURCE_DIR}/Deps/Libs/Linux/libglfw3.a)
endif()

if (MSVC)
    target_link_libraries(Orion ${CMAKE_CURRENT_SOURCE_DIR}/Deps/Libs/Windows/*.lib)
endif()

