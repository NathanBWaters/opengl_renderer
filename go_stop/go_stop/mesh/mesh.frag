#version 330 core
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)
in vec2 textureCoord;
in vec3 normal;
in vec3 fragmentPosition;

// What is emitting from the vertex shader
out vec4 FragColor;

// The texture we will be displaying
uniform sampler2D meshTexture1;
uniform sampler2D meshTexture2;

// Lighting Information
uniform vec3 ambientLight;
uniform vec3 pointLightPosition1;

void main()
{
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(pointLightPosition1 - fragmentPosition);
    
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec4 textureColor = mix(texture(meshTexture1, textureCoord), texture(meshTexture2, textureCoord), 0.5);
    FragColor = (vec4(ambientLight + diffuse, 1.0)) * textureColor;
}

