#include "vertex.h"

Vertes::Vertes(std::string filename)
{
    scene = importer.ReadFile(filename,aiProcess_Triangulate | aiProcess_FlipUVs| aiProcess_GenSmoothNormals);
    std::cout << "Model loaded successfully!" << "\n";
}


std::vector<Vertex> Vertes::readvertices()
{
    for(int m =0;m<scene->mNumMeshes;m++)
    {
        aiMesh* mesh = scene->mMeshes[m];
    

        for(int i=0;i<mesh->mNumVertices;i++)
        {
            float x = mesh->mVertices[i].x;
            float y = mesh->mVertices[i].y;
            float z = mesh->mVertices[i].z;

            
            float xn = mesh->mNormals[i].x;
            float yn = mesh->mNormals[i].y;
            float zn = mesh->mNormals[i].z;

            if(!mesh->HasNormals()){
                std::cout<<"normals not found"<<"\n";
                exit(-1);
            }
            

            Vertex vertr = {glm::vec3(x,y,z),glm::vec3(1.0f,1.0f,1.0f),glm::vec3(xn,yn,zn)};
            verticies.push_back(vertr);
        }

    }

    return verticies;
}


std::vector<GLuint> Vertes::readIndicies()
{
    int prev_indicies = 0;

    for(int m =0;m<scene->mNumMeshes;m++)
    {
        aiMesh* mesh = scene->mMeshes[m];

        for(int i = 0;i<mesh->mNumFaces;i++)
        {
            aiFace face = mesh->mFaces[i];

            for(int j=0;j<face.mNumIndices;j++){

                indicies.push_back(face.mIndices[j] + prev_indicies);
            }
        }
        prev_indicies += mesh->mNumVertices;
    }
    return indicies;
}


unsigned int Vertes::indcieies_count(){
    return indicies.size();
}