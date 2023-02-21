project(Orion)

cmake_minimum_required(VERSION 3.20)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Orion Main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Graphics/Window.cpp glad.c)
target_include_directories(Orion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Deps/Include/)

if(UNIX)
    target_link_libraries(Orion ${CMAKE_CURRENT_SOURCE_DIR}/Deps/Libs/Linux/libglfw3.a)
endif()

if (MSVC)
    target_link_libraries(Orion ${CMAKE_CURRENT_SOURCE_DIR}/Deps/Libs/Windows/*.lib)
endif()

