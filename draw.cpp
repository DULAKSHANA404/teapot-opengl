#include "draw.h"
#include <glm/gtc/type_ptr.hpp>

Camera camera;

Draw::Draw(GLFWwindow* window){
    this->window = window;
}

void Draw::setter_for_program(GLuint program){
    this->program = program;
}

void Draw::setter_for_VAO(GLuint VAO){
    this->VAO = VAO;
}


void Draw::paint(unsigned int sizeofindicies){
    
    glm::mat4 projectionmatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 1000.0f);
    GLuint fulltransformmetrixuniformlocationid = glGetUniformLocation(program,"fulltransformmatrix");

    GLuint ambientlightid =glGetUniformLocation(program,"ambientlight");
    glm::vec3 ambientlight(0.1f,0.1f,0.1f);
    glm::vec3 lightposition(200.0f, 100.0f, 200.0f);

    GLuint lightpositionlocationid = glGetUniformLocation(program,"lightpositionlocation");

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        //glClearColor(0.1f, 0.1f, 0.15f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(glfwGetKey(window,GLFW_KEY_W)==GLFW_PRESS){
            camera.moveforward();
        }

        if(glfwGetKey(window,GLFW_KEY_S)==GLFW_PRESS){
            camera.movebackward();
        }

        if(glfwGetKey(window,GLFW_KEY_A)==GLFW_PRESS){
            camera.moveleft();
        }

        if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS){
            camera.moveright();
        }

        if(glfwGetKey(window,GLFW_KEY_SPACE)==GLFW_PRESS){
            camera.moveup();
        }

        if(glfwGetKey(window,GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS){
            camera.movedown();
        }



        glUseProgram(program);
        glUniform3fv(ambientlightid,1,&ambientlight[0]);
        glBindVertexArray(VAO);
        
        //teapot

        glm::mat4 rotatiommatrix = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(-0.5f, 0.0f, -5.0f));

        glm::mat4 viewmatrix = camera.getworldtoviewmatrix();

        glm::mat4 translatemodelmatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.01f, -3.0f));

        glm::mat4 fulltransformmatrix = projectionmatrix*viewmatrix  * translatemodelmatrix * rotatiommatrix;
        glUniformMatrix4fv(fulltransformmetrixuniformlocationid,1,GL_FALSE,&fulltransformmatrix[0][0]);
        glUniform3fv(lightpositionlocationid,1,&lightposition[0]);

        glDrawElements(GL_TRIANGLES, sizeofindicies, GL_UNSIGNED_INT, 0);


        glfwSwapBuffers(window);
    }
}