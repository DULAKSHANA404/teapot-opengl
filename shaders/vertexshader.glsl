#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec3 normal;

uniform vec3 lightpositionlocation;
uniform vec3 ambientlight;

out vec3 theNormal;
out vec3 thepositions;

uniform mat4 fulltransformmatrix;

void main() {
    gl_Position = fulltransformmatrix*vec4(aPos,1.0);
    theNormal = normal;
    thepositions = aPos;

}
