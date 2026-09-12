#version 330 core

in vec3 theNormal;
in vec3 thepositions;
out vec4 FragColor;

uniform vec3 lightpositionlocation;

void main() {
    vec3 lightvector = normalize(lightpositionlocation-thepositions);
    float bright = dot(lightvector,theNormal);
    FragColor = vec4(bright,bright,bright, 1.0);
}