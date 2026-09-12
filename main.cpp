#include "mainwindow.h"
#include "draw.h"
#include "buffers.h"
#include "vertex.h" 


int main(){
    MainWindow mainwindow(800,600);
    GLFWwindow* window = mainwindow.getter_for_window();
    Buffers buffers;
    buffers.CompileShaders();

    Vertes ver("teapot.obj");
    
    std::vector<Vertex> vertices = ver.readvertices();
    std::vector<GLuint> indices = ver.readIndicies();
    unsigned int sizeofindicies = ver.indcieies_count();    

    buffers.CompileBuffers(vertices.data(), vertices.size() * sizeof(Vertex), indices.data(), indices.size() * sizeof(GLuint));

    GLuint program = buffers.getter_for_programID();
    GLuint VAO = buffers.getter_for_VAO();

    
    Draw draw(window);
    draw.setter_for_program(program);
    draw.setter_for_VAO(VAO);
    
    draw.paint(sizeofindicies);

}