/*
=============================================================================================

                            OpenGL on Windows Engine Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "glow.hpp"

namespace GLOW {
    void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    namespace Init {
        void GLFW() {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }

        void GLAD() {
            if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
                throw std::runtime_error("Failed to init GLAD");
            }
        }
    }

    Window::Window(const int width, const int height, const std::string& title) {
            window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

            if (!window) {
                throw std::runtime_error("Failed to create GLFW window");
            }

        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    Window::~Window() {
        glfwDestroyWindow(window);
    }

    GLFWwindow* Window::getWindow() {
        return window;
    }

    Color& Window::getColor() {
        return color;
    }

    void Window::setColor(const Color& color) {
        this->color = color;
    }

    namespace Core {
        void runMainLoop(Window& window) {
            const auto&[red, green, blue, alpha] = window.getColor();

            while (!glfwWindowShouldClose(window.getWindow())) {
                glClearColor(red, green, blue, alpha);
                glClear(GL_COLOR_BUFFER_BIT);
                glfwSwapBuffers(window.getWindow());
                glfwPollEvents();
            }
        }

        void exit() {
            glfwTerminate();
        }

    }

}