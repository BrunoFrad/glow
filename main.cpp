#include "engine/glow.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main() {
    try {
        GLOW::Init::GLFW(); // Init GLOW

        GLOW::Window window(1280, 720, "GLOW Engine");
        window.setColor({0.13f, 0.13f, 0.13f, 1.0f});

        GLOW::Init::GLAD(); // init GLAD

        // --- Vertex Shader ---
        std::ifstream vertexShaderFile("../engine/shaders/basic/vertex.txt");
        if (!vertexShaderFile.is_open()) {
            std::cerr << "Failed to open the vertex shader!" << std::endl;
            return 1;
        }

        std::stringstream vertexBuffer;
        vertexBuffer << vertexShaderFile.rdbuf();
        std::string vertexShaderString = vertexBuffer.str();
        const char* vertexShaderSource = vertexShaderString.c_str();
        vertexShaderFile.close();

        // --- Fragment Shader ---
        std::ifstream fragmentShaderFile("../engine/shaders/basic/fragment.txt");
        if (!fragmentShaderFile.is_open()) {
            std::cerr << "Failed to open the fragment shader!" << std::endl;
            return 1;
        }

        std::stringstream fragmentBuffer;
        fragmentBuffer << fragmentShaderFile.rdbuf();
        std::string fragmentShaderString = fragmentBuffer.str();
        const char* fragmentShaderSource = fragmentShaderString.c_str();
        fragmentShaderFile.close();

        auto mesh = GLOW::Triangle(0.3, 0.4, vertexShaderSource, fragmentShaderSource);
        std::vector<GLOW::Mesh*> meshes;
        meshes.push_back(&mesh);

        GLOW::Core::runMainLoop(window, meshes); // Main Loop

        GLOW::Core::exit();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
