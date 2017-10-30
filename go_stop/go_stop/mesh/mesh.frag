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

// ViewMatrix position (the position of the camera)
uniform vec3 viewPosition;

struct Material {
    sampler2D ambient;    // what color this object reflects under ambient lighting; this is usually the same as the object's color
    sampler2D diffuse;    // defines the color of the object under diffuse lighting; this is also usually the same as the object's color
    sampler2D specular;   // sets the color impact a specular light has on the object (or possibly even reflect an object-specific specular
                     //     highlight color)
    float shininess; // impacts the scattering/radius of the specular highlight
};

struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    
    float constant;
    float linear;
    float quadratic;
};

uniform int NUM_POINT_LIGHTS;
uniform PointLight pointLights[50];

uniform Material material;



vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragmentPosition, vec3 viewDir)
{
    //////////////////////////////////////////////////////////////////
    // Calculate ambient lighting
    //////////////////////////////////////////////////////////////////
    vec3 ambient = light.ambient * vec3(texture(material.ambient, textureCoord));
    
    //////////////////////////////////////////////////////////////////
    // Calculate diffuse lighting
    //////////////////////////////////////////////////////////////////
    // we want to normalize the normal for the fragment, so that dot products will be less than 1.
    vec3 normalizedNormal = normalize(normal);
    
    // we can get the light direction by normalizing the vector produced by
    // subtracting the point lights position with the fragments position.
    vec3 lightDirection = normalize(light.position - fragmentPosition);
    
    // Finding the dot product between the normal and the light direction to determine
    // the impact of the light on the fragment
    float diff = max(dot(normalizedNormal, lightDirection), 0.0);
    
    vec3 diffuse = (diff * vec3(texture(material.diffuse, textureCoord))) * light.diffuse;
    
    //////////////////////////////////////////////////////////////////
    // Calculate specular lighting
    //////////////////////////////////////////////////////////////////
    
    // We want to know the vector that the light reflects off of the fragment.
    vec3 reflectDirection = reflect(-lightDirection, normalizedNormal);
    
    // the higher the dot product between the view direction
    float specularHighlight = pow(max(dot(viewDir, reflectDirection), 0.0), material.shininess);
    vec3 specular = (specularHighlight * vec3(texture(material.specular, textureCoord))) * light.diffuse;
    
    //////////////////////////////////////////////////////////////////
    // Combine lights and textures and add attenuation
    //////////////////////////////////////////////////////////////////
    // length automatically calculates the distance between two point vectors
    float distance = length(light.position - fragmentPosition);
    
    float attenuation = 1.0 / (light.constant + light.linear * distance +
                               light.quadratic * (distance * distance));
    
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return ambient + diffuse + specular;
}

void main()
{
    // the view direction, which is the angle at which the camera's view
    // hits the fragment.
    vec3 viewDir = normalize(viewPosition - fragmentPosition);
    
    vec3 pointLightResult = vec3(0.0, 0.0, 0.0);
    for (int i = 0; i < NUM_POINT_LIGHTS; i++) {
        pointLightResult += calcPointLight(pointLights[i], normal, fragmentPosition, viewDir);
    }
    FragColor = vec4(pointLightResult, 1.0);
}

