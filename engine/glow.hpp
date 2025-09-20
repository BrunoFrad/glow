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

    class Mesh {
    private:

        unsigned int vertexShader{};
        unsigned int fragmentShader{};

    protected:
        unsigned int VAO{};
        unsigned int shaderProgram{};
        unsigned int VBO{};
        std::vector<float> vertices;

    public:
        Mesh(const std::vector<float>& vertices, const char* vertexSrc, const char* fragmentSrc);
        void setBuffersData();
        void loadVertexShader(const char* vertexSrc);
        void loadFragmentShader(const char* fragmentSrc);
        void createShaderProgram();
        virtual void draw();
        virtual ~Mesh();
    };

    class Triangle : public Mesh {
    public:
        Triangle(float width, float height, const char * vertexSrc, const char * fragmentSrc);
        void draw() override;
    };

    namespace Core {
        void runMainLoop(Window& window, std::vector<Mesh*>& meshes);

        void exit();

    }

}