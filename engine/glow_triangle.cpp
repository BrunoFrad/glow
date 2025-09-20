/*
=============================================================================================

                            OpenGL on Windows Engine Triangle Subnamespace Source File

                                    by : Bruno Frade
                                    date : 19/09/2025

==============================================================================================
*/

#include "glow.hpp"

GLOW::Triangle::Triangle(float width, float height, const char *vertexSrc, const char *fragmentSrc) : Mesh({-width, -height, 0.f, width, -height, 0.f, 0.f, height, 0.f}, vertexSrc, fragmentSrc){

}

void GLOW::Triangle::draw() {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}