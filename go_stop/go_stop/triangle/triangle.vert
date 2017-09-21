#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 aColorCoord;

uniform vec3 offset;

out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 textureCoord;

void main() {
    gl_Position = vec4(aPos.x + offset.x, aPos.y + offset.y, aPos.z - offset.z, 1.0);
    vertexColor = vec4(vColor, 1.0);
    textureCoord = aColorCoord;
}