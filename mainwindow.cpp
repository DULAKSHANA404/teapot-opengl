#include "mainwindow.h"

MainWindow::MainWindow(const int width,const int height){
    glfwInit();
    window = glfwCreateWindow(width,height,"teapot??",0,0);
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
}

GLFWwindow* MainWindow::getter_for_window(){
    return window;
}

MainWindow::~MainWindow(){
    glfwDestroyWindow(window);
    glfwTerminate();
}