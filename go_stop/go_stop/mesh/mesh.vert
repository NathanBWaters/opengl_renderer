#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normalVector;

// output texture coordinates in local space
out vec2 textureCoord;

// output normal coordinates in world space
out vec3 normal;

// idk have to look this up...   in world space
out vec3 fragmentPosition;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
    // Output vertex position
    vec4 local_position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    // note that we read the multiplication from right to left
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * local_position;
    
    fragmentPosition = vec3(modelMatrix * vec4(aPos, 1.0));
    normal = mat3(transpose(inverse(modelMatrix))) * normalVector;
    textureCoord = texCoord;
}
