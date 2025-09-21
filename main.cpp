/*
=============================================================================================

                            OpenGL on Windows Engine Main Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/


#include "engine/glow.hpp"

int main() {
    try {
        GLOW::Init::GLFW(); // Init GLOW

        GLOW::Window window(1280, 720, "GLOW Engine");
        window.setColor({0.13f, 0.13f, 0.13f, 1.0f});

        GLOW::Init::GLAD(); // init GLAD

        GLOW::Shader shader_orange("../engine/shaders/basic/vertex.txt", "../engine/shaders/basic/fragment.txt");
        GLOW::Shader shader_yellow("../engine/shaders/basic/vertex.txt", "../engine/shaders/basic/fragment_yellow.txt");

        auto mesh = GLOW::Triangle(-0.6f, 0, 0.3f, 0.4f, shader_orange ,GL_STATIC_DRAW);
        auto mesh2 = GLOW::Triangle(0.6f, 0, 0.3f, 0.4f, shader_yellow, GL_STATIC_DRAW);
        std::vector<GLOW::Mesh*> meshes;
        meshes.push_back(&mesh);
        meshes.push_back(&mesh2);

        GLOW::Core::runMainLoop(window, meshes); // Main Loop
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    GLOW::Core::exit();

    return 0;
}
