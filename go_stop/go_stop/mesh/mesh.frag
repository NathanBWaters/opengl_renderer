#version 330 core
// the input variable from the vertex shader (same name and same type)
in vec4 vertexColor;
// output texture coordinates in local space
in vec2 textureCoord;
// output normal coordinates in world space
in vec3 normal;
// Where the fragment is in in world space
in vec3 fragmentPosition;

// What is emitting from the vertex shader
out vec4 FragColor;

// The texture we will be displaying
uniform sampler2D meshTexture1;
uniform sampler2D meshTexture2;

// Lighting Information
uniform vec3 ambientLight;
uniform vec3 pointLightPosition1;

// ViewMatrix position (the position of the camera)
uniform vec3 viewPosition;

struct Material {
    vec3 ambient;    // what color this object reflects under ambient lighting; this is usually the same as the object's color
    vec3 diffuse;    // defines the color of the object under diffuse lighting; this is also usually the same as the object's color
    vec3 specular;   // sets the color impact a specular light has on the object (or possibly even reflect an object-specific specular
                     //     highlight color)
    float shininess; // impacts the scattering/radius of the specular highlight
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

uniform Material material;

void main()
{
    vec3 lightColor = vec3(0.8, 0.8, 0.8);

    //////////////////////////////////////////////////////////////////
    // Calculate ambient lighting
    //////////////////////////////////////////////////////////////////
    vec3 ambient = ambientLight * material.ambient;
    
    //////////////////////////////////////////////////////////////////
    // Calculate diffuse lighting
    //////////////////////////////////////////////////////////////////
    // we want to normalize the normal for the fragment, so that dot products will be less than 1.
    vec3 normalizedNormal = normalize(normal);
    
    // we can get the light direction by normalizing the vector produced by
    // subtracting the point lights position with the fragments position.
    vec3 lightDirection = normalize(pointLightPosition1 - fragmentPosition);
    
    // Finding the dot product between the normal and the light direction to determine
    // the impact of the light on the fragment
    float diff = max(dot(normalizedNormal, lightDirection), 0.0);
    
    vec3 diffuse = (diff * material.diffuse) * lightColor;
    
    //////////////////////////////////////////////////////////////////
    // Calculate specular lighting
    //////////////////////////////////////////////////////////////////
    // the view direction, which is the angle at which the camera's view
    // hits the fragment.
    vec3 viewDir = normalize(viewPosition - fragmentPosition);
    
    // We want to know the vector that the light reflects off of the fragment.
    vec3 reflectDirection = reflect(-lightDirection, normalizedNormal);
    
    // the higher the dot product between the view direction
    float specularHighlight = pow(max(dot(viewDir, reflectDirection), 0.0), material.shininess);
    vec3 specular = (specularHighlight * material.specular) * lightColor;
    
    //////////////////////////////////////////////////////////////////
    // Combine lights and textures
    //////////////////////////////////////////////////////////////////
    vec4 textureColor = mix(texture(meshTexture1, textureCoord), texture(meshTexture2, textureCoord), 0.5);
    FragColor = (vec4(ambient + diffuse + specular, 1.0)) * textureColor;
}

