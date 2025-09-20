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
}