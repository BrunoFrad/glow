/*
=============================================================================================

                            OpenGL on Windows Engine Window Namespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "glow.hpp"

GLOW::Window::Window(const int width, const int height, const std::string& title) {
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!window) {
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

GLOW::Window::~Window() {
    glfwDestroyWindow(window);
}

GLFWwindow* GLOW::Window::getWindow() {
    return window;
}

GLOW::Color& GLOW::Window::getColor() {
    return color;
}

void GLOW::Window::setColor(const Color& color) {
    this->color = color;
}