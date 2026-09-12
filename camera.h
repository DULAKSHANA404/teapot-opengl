#pragma once

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

class Camera{
private:
    glm::vec3 position;
    glm::vec3 viewdir;
    const glm::vec3 up;
    const float speed;


public:
    Camera();
    glm::mat4 getworldtoviewmatrix();

    void moveforward();
    void movebackward();
    void moveright();
    void moveleft();
    void moveup();
    void movedown();

};