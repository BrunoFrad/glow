/*
=============================================================================================

                            OpenGL on Windows Engine Core Namespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "glow.hpp"

namespace GLOW::Core {
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