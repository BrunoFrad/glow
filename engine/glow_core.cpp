/*
=============================================================================================

                            OpenGL on Windows Engine Core Namespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include <format>

#include "glow.hpp"

namespace GLOW::Core {
    void runMainLoop(Window& window, std::vector<Mesh*>& meshes) {
        while (!glfwWindowShouldClose(window.getWindow())) {
            const auto&[red, green, blue, alpha] = window.getColor();

            glClearColor(red, green, blue, alpha);
            glClear(GL_COLOR_BUFFER_BIT);

            for (auto& mesh : meshes) {
                mesh->draw();
            }

            glfwSwapBuffers(window.getWindow());
            glfwPollEvents();
        }
    }

    void exit() {
        glfwTerminate();
    }

}