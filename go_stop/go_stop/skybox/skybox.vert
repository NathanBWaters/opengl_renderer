#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 texture;
layout (location = 2) in vec3 normal;
out vec3 TexCoords;

uniform mat4 modelMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main() {
    TexCoords = aPos;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
}
