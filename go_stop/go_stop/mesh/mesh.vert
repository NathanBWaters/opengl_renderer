#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normalVector;

// output texture coordinates in local space
out vec2 textureCoord;

// output normal coordinates in world space
out vec3 normal;

// Where the fragment is in in world space
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
    
    // For normal vectors, we can't just multiply them by the world coordinates.
    // Normal vectors do not have a homogeneous coordinate, (the w component of a vertex position)
    // This means that translations do and should not have any effect on the normal vectors
    // They do not have direction, so we multiply it by the upper 3x3 matrix in the world
    // coordinates so only rotation and scale are affected.
    // Second, if the model matrix would perform a non-uniform scale, the vertices would be changed
    // in such a way that the normal vector is not perpendicular to the surface anymore, so we can't
    // transform the normal vectors with such a model matrix
    // Whenever we apply a non-uniform scale (note: uniform scales won't hurt the normals since their
    // directions do not change, just their magnitude which is easily fixed by normalizing them) the
    // normal vectors are not perpendicular to the corresponding surface anymore which distorts the
    // lighting.
    normal = mat3(transpose(inverse(modelMatrix))) * normalVector;
    textureCoord = texCoord;
}
