cmake_minimum_required(VERSION 4.0)
project(glow)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(glow
        main.cpp
        glad.c
        engine/glow.hpp
        engine/glow.cpp
        engine/glow_init.cpp
        engine/glow_window.cpp
        engine/glow_core.cpp
        engine/glow_Mesh.cpp
        engine/glow_triangle.cpp
        engine/glow_shader.cpp
)

target_link_libraries(glow PRIVATE
        glfw3
        opengl32
)
