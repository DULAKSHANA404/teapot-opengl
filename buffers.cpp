#include "buffers.h"
#include <iostream>
#include <fstream>
#include <sstream>


std::string readshadercode(std::string filepath)
{
    std::fstream file;
    file.open(filepath,std::ios::in);
    std::stringstream row;
    row<<file.rdbuf();
    return row.str();
}

void Buffers::CompileBuffers(const void* verticies ,size_t sizeofverticies ,const void* indicies,size_t sizeofindicies)
{
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeofverticies,verticies,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,normal));



    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeofindicies,indicies,GL_STATIC_DRAW);
    
    glBindVertexArray(0);
}


void Buffers::CompileShaders()
{
    std::string temp1 = readshadercode("shaders/vertexshader.glsl");
    const char* vertexshadersource = temp1.c_str();

    std::string temp2 = readshadercode("shaders/fragmentshader.glsl");
    const char* fragmentshadersource = temp2.c_str();

    programID = glCreateProgram();

    GLuint vertexshaderID,fragmentshaderID;

    vertexshaderID = glCreateShader(GL_VERTEX_SHADER);
    fragmentshaderID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexshaderID,1,&vertexshadersource,0);
    glShaderSource(fragmentshaderID,1,&fragmentshadersource,0);

    glCompileShader(vertexshaderID);
    glCompileShader(fragmentshaderID);

    glAttachShader(programID,vertexshaderID);
    glAttachShader(programID,fragmentshaderID);

    glLinkProgram(programID);

    glDeleteShader(vertexshaderID);
    glDeleteShader(fragmentshaderID);
}


GLuint Buffers::getter_for_programID()
{
    return programID;
}

GLuint Buffers::getter_for_VAO()
{
    return VAO;
}