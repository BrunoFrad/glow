/*
=============================================================================================

                            OpenGL on Windows Engine Header File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#pragma once

// OpenGL includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// C++ STD includes
#include <iostream>

namespace GLOW {

    typedef struct {
        GLfloat red, green, blue, alpha;
    } Color;

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    namespace Init {
        void GLFW();

        void GLAD();
    }

    class Window {
    private:
        GLFWwindow* window;
        Color color = {0.0f, 0.0f, 0.0f, 1.0f};
    public:
        Window(const int width, const int height, const std::string& title);

        ~Window();

        GLFWwindow* getWindow();

        Color& getColor();

        void setColor(const Color& color);
    };

    namespace Core {
        void runMainLoop(Window& window);

        void exit();

    }

}