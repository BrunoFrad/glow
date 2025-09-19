cmake_minimum_required(VERSION 4.0)
project(glow)

set(CMAKE_CXX_STANDARD 20)

add_executable(glow
        main.cpp
        glad.c
        glow.hpp
        glow.cpp
)

target_link_libraries(glow PRIVATE
        glfw3
        opengl32
)