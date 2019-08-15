#version 330 core
// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 squareVertices;
layout (location = 1) in vec4 xyzs; // Position of the center of the particle and size of the square
layout (location = 2) in vec4 color; // Position of the center of the particle and size of the square

out vec2 textureCoordinates;
out vec4 particleColor;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
    float particleSize = xyzs.w; // because we encoded it this way.
    vec3 particleCenter_wordspace = xyzs.xyz;

    // UV of the vertex. No special space for this one.
    textureCoordinates = squareVertices.xy + vec2(0.5, 0.5);
    particleColor = color;
    
    // note that we read the multiplication from right to left
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(particleCenter_wordspace, 1.0);
}
