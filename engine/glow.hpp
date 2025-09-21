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
#include <vector>
#include <fstream>
#include <sstream>

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
        Window(int width, int height, const std::string& title);

        ~Window();

        GLFWwindow* getWindow();

        Color& getColor();

        void setColor(const Color& color);
    };

    class Shader {
    protected:
        unsigned int shaderProgram;
        unsigned int vertexShader;
        unsigned int fragmentShader;

        void loadVertexShader(const char* vertexSrc);
        void loadFragmentShader(const char* fragmentSrc);
        void createShaderProgram();

    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        void use();
        ~Shader();
    };

    class Mesh {
    protected:
        unsigned int VAO{};
        Shader& shader;
        unsigned int VBO{};
        std::vector<float> vertices;

    public:
        Mesh(const std::vector<float>& vertices, Shader& shader, long mode);
        void setBuffersData(long mode);
        virtual void draw();
        virtual ~Mesh();
    };

    class Triangle : public Mesh {
    public:
        Triangle(float x, float y, float width, float height, Shader& shader, long mode);
        void draw() override;
    };

    namespace Core {
        void runMainLoop(Window& window, std::vector<Mesh*>& meshes);

        void exit();

    }

}