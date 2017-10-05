#version 330 core
out vec4 FragColor;
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)
in vec2 textureCoord;

// The texture we will be displaying
uniform sampler2D triangleTexture1;
uniform sampler2D triangleTexture2;

void main()
{
    FragColor = mix(texture(triangleTexture1, textureCoord), texture(triangleTexture2, textureCoord), 0.5);
}
