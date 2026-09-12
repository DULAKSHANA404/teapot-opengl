#include "camera.h"

Camera::Camera():
    position(0.0f, 100.0f, 210.0f),
    viewdir(0.0f, -0.4f, -1.0f),
    up(0.0f, 1.0f, 0.0f),
    speed(0.5f) {}

glm::mat4 Camera::getworldtoviewmatrix(){
    return glm::lookAt(position,position+viewdir,up);
}

void Camera::moveforward(){
    position = position + viewdir*speed;
}

void Camera::movebackward(){
    position = position - viewdir*speed;
}

void Camera::moveright(){
    glm::vec3 right = glm::normalize(glm::cross(viewdir,up));
    position = position + right*speed;
}

void Camera::moveleft(){
    glm::vec3 left = glm::normalize(glm::cross(viewdir,up));
    position = position- left*speed;
}

void Camera::moveup(){
    position = position  + up*speed;
}

void Camera::movedown(){
    position = position - up*speed;
}
