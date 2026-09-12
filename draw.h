#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.h"

class Draw{
private:
    GLFWwindow* window;
    GLuint program,VAO;

public:
    Draw(GLFWwindow* window);
    void setter_for_program(GLuint program);
    void setter_for_VAO(GLuint VAO);
    void paint(unsigned int sizeofindicies);

};