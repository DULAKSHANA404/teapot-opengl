#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vertex.h"

class Buffers{
private:
    GLuint programID,VBO,EBO,VAO;

public:
    GLuint getter_for_programID();
    GLuint getter_for_VAO();
    void CompileShaders();
    void CompileBuffers(const void* verticies , size_t sizeofverticies ,const void* indicies,size_t sizeofindicies);
};