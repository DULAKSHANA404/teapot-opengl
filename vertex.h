#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>


//VERTEX_COUNT 3644
//INDEX_COUNT 18960

struct Vertex{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
};


extern std::vector<Vertex> vertex;

class Vertes{
private:
    Assimp::Importer importer;
    const aiScene* scene;
    std::vector<Vertex> verticies;
    std::vector<GLuint> indicies;
    std::vector<float> normals;

public:
    Vertes(std::string filename);
    std::vector<Vertex> readvertices();
    std::vector<GLuint> readIndicies();
    unsigned int indcieies_count();

};
