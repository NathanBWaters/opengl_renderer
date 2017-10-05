#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 aColorCoord;

out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 textureCoord;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
    vec4 local_position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    
    // note that we read the multiplication from right to left
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * local_position;

    vertexColor = vec4(vColor, 1.0);
    textureCoord = aColorCoord;
}
