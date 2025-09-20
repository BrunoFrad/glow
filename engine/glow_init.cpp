/*
=============================================================================================

                            OpenGL on Windows Engine Init Namespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "glow.hpp"

namespace GLOW::Init {
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