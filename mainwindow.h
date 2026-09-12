#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class MainWindow{
private:
    GLFWwindow* window;

public:
    MainWindow(const int width,const int height);
    GLFWwindow* getter_for_window();
    ~MainWindow();
};