/*
=============================================================================================

                            OpenGL on Windows Engine Triangle Subnamespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "glow.hpp"

GLOW::Triangle::Triangle(float x, float y, float width, float height, Shader& shader, const long mode) : Mesh({-width+x, -height, 0.f, width+x, -height, 0.f, x, height, 0.f}, shader, mode){}

void GLOW::Triangle::draw() {
    this->shader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}