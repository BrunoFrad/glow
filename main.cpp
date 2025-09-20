/*
=============================================================================================

                            OpenGL on Windows Engine Main File Example

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "engine/glow.hpp"

int main() {

    try {
        GLOW::Init::GLFW(); // Init GLOW

        GLOW::Window window(1280, 720, "GLOW Engine"); // Create a GLOW Window object
        window.setColor({0.13f, 0.13f, 0.13f, 1.0f}); // Set the window color to a dark gray (OPTIONAL)

        GLOW::Init::GLAD(); // init GLAD

        GLOW::Core::runMainLoop(window); // Main Loop

        GLOW::Core::exit();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}