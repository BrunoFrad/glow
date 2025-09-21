/*
=============================================================================================

                            OpenGL on Windows Engine Mesh Subnamespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/


#include "glow.hpp"

GLOW::Mesh::Mesh(const std::vector<float>& vertices, Shader& shader, const long mode) : shader(shader) {
    this->vertices = vertices;
    setBuffersData(mode);
    this->shader = shader;
}

void GLOW::Mesh::setBuffersData(const long mode) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), mode);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GLOW::Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}


void GLOW::Mesh::draw() {
    this->shader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);
    glBindVertexArray(0);
}