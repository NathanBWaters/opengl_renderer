//
//  scene_object.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/24/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//
#include <QDebug>
#include <QOpenGLFunctions>

#include "scene_object.hpp"
#include "../scene/Scene.hpp"
#include "../point_light/point_light.hpp"

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;

SceneObject::SceneObject(Scene* scene,
           glm::vec3 position,
           glm::vec3 rotation,
           glm::vec3 scale) {
    this->scene = scene;

    Translation = position;
    Scale = scale;
    
    this->rotationX = rotation.x;
    this->rotationY = rotation.y;
    this->rotationZ = rotation.z;
    
    // white plastic
    this->scene_objectMaterial = Material{
        glm::vec3(0.2f, 0.2f, 0.2f),     // ambient
        glm::vec3(0.55f, 0.55f, 0.55f),  // diffuse
        glm::vec3(1.7f, 1.7f, 1.7f),     // specular
        32.0f,                   // shininess
    };
    
    addToScene();
}

void SceneObject::setShader(Shader newShader) {
    this->scene_objectShader = newShader;
}

Shader SceneObject::getShader() {
    return this->scene_objectShader;
}

void SceneObject::init() {
    setDefaultShader();
    resetShader();
    
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float * vertices = getVertices();
    glGenVertexArrays(1, &scene_objectVAO);
    glGenBuffers(1, &scene_objectVBO);
    
    // VAO
    // You bind the Vertex Array Object first, then bind and set vertex buffer(s), and then
    // configure vertex attributes(s).
    glBindVertexArray(scene_objectVAO);
    
    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, scene_objectVBO);
    
    glBufferData(GL_ARRAY_BUFFER,
                 getNumVertices() * getSpan() * sizeof(float),
                 vertices,
                 GL_STATIC_DRAW);
    
    // vertices position, location == 0, span 3
    glVertexAttribPointer(0,                 // location in vertex shader
                          3,                 // number of vertices for positional value
                          GL_FLOAT,          // data type
                          GL_FALSE,          //
                          getSpan() * sizeof(float), // span of one vertex data
                          (void*)0);         // where on the vertex does it start
    // you must enable to position of the vertex location of position.  You can see the size of the
    // vertex attribut array by calling GL_MAX_VERTEX_ATTRIBS.  They are disabled by default.
    glEnableVertexAttribArray(0);
    
    // normals vertex, location == 1, span 3
    glVertexAttribPointer(1,                          // location in vertex shader
                          3,                          // number of vertices for normal vector
                          GL_FLOAT,                   // data type
                          GL_FALSE,                   //
                          getSpan() * sizeof(float),  // span of one vertex
                          (void*)(5* sizeof(float))); // where on the vertex does it start
    glEnableVertexAttribArray(1);                     // location of position
    
    // texture position, location == 2, span 2
    glVertexAttribPointer(2,                          // location in vertex shader
                          2,                          // number of vertices for texture value
                          GL_FLOAT,                   // data type
                          GL_FALSE,                   //
                          getSpan() * sizeof(float),          // span of one vertex
                          (void*)(3* sizeof(float))); // where on the vertex does it start
    glEnableVertexAttribArray(2);                     // location of position
    
    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    ////////////////////////////////////////////////
    // Set texture information
    ////////////////////////////////////////////////
    setTexture();
    
    ////////////////////////////////////////////////
    // Set material information
    ////////////////////////////////////////////////
    setMaterial();
    
    ////////////////////////////////////////////////
    //  Light Information
    ////////////////////////////////////////////////
    setLights();
    
    // Unbind the VBO and VAO at the end, but not the EBO because it's part of the VAO.
    
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens.
    // Modifying other VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs)
    // when it's not directly necessary.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    // Projection Matrix to convert view space to clip space
    glm::mat4 projection;
    projectionMatrix = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
}

void SceneObject::setLights() {
    std::vector<PointLight*> scenePointLights = this->scene->getLights();
    
    int numPointLightsLoc = glGetUniformLocation(scene_objectShader.ID, "NUM_POINT_LIGHTS");
    glUniform1i(numPointLightsLoc, scenePointLights.size());
    
    for(int i = 0; i < scenePointLights.size(); i++) {
        std::string index = std::to_string(i);
        PointLight* pointLight = scenePointLights[i];
        
        // Set ambient light
        glm::vec3 lightColor = pointLight->getLightColor();

        int ambientLightLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLight[" + index + "].ambient").c_str());
        glUniform3fv(ambientLightLoc, 1, &lightColor[0]);
        
        // Set specular light
        int specularLightLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLights[" + index + "].specular").c_str());
        glUniform3fv(specularLightLoc, 1, &lightColor[0]);
        
        // Set diffuse light
        int diffuseLightLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLights[" + index + "].diffuse").c_str());
        glUniform3fv(diffuseLightLoc, 1, &lightColor[0]);
        
        // Set point light 1 position
        int pointLightLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLights[" + index + "].position").c_str());
        glm::vec3 lightPosition = pointLight->getPosition();
        glUniform3fv(pointLightLoc, 1, &lightPosition[0]);
        
        // Set attenuation constants
        int lightConstantLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLights[" + index + "].constant").c_str());
        glUniform1f(lightConstantLoc, 0.5f);
        
        int lightLinearLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLights[" + index + "].linear").c_str());
        glUniform1f(lightLinearLoc, 0.045f);
        
        int lightQuadraticLoc = glGetUniformLocation(scene_objectShader.ID, ("pointLights[" + index + "].quadratic").c_str());
        glUniform1f(lightQuadraticLoc, 0.016f);
    }
}

void SceneObject::render(glm::vec3 positionT,
                  glm::vec3 rotationT,
                  glm::vec3 scaleT)
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    this->scene_objectShader.use();
    
    setLights();
    
    int globalLightLoc = glGetUniformLocation(scene_objectShader.ID, "globalLight");
    glm::vec3 ambientLight = this->scene->getAmbientLight();
    glUniform3f(globalLightLoc, ambientLight.r, ambientLight.g, ambientLight.b);

    glm::mat4 scalingMatrix = glm::scale(glm::mat4(), Scale);
    
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(), rotationX, glm::vec3(1.0f, 0.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotationY, glm::vec3(0.0f, 1.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotationZ, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 translationMatrix = glm::translate(glm::mat4(), Translation);
    
    glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;
    
    // Set viewMatrix position (which is the camera position)
    Camera *camera = this->scene->getCamera();
    int viewPositionLoc = glGetUniformLocation(scene_objectShader.ID, "viewPosition");
    glUniform3f(viewPositionLoc, camera->Position.x, camera->Position.y, camera->Position.z);
    
    // Set the model matrix (where the scene_object is in world space)
    int modelMatrixLoc = glGetUniformLocation(scene_objectShader.ID, "modelMatrix");
    glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    
    // Set view matrix
    int viewMatrixLoc = glGetUniformLocation(scene_objectShader.ID, "viewMatrix");
    glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    
    // Set projection matrix
    int projectionMatrixLoc = glGetUniformLocation(scene_objectShader.ID, "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    
    // setting image one, which is on the texture unit GL_TEXTURE0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, scene_objectTextureLoc1);
    // setting image two, which is on the texture unit GL_TEXTURE1
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, scene_objectTextureLoc2);
    
    glBindVertexArray(scene_objectVAO);
    
    // Drawing from the EBO through the VAO.
    glDrawArrays(GL_TRIANGLES, 0, getNumVertices());
    
    glBindVertexArray(0);
}

void SceneObject::addToScene() {
    this->scene->addItem(this);
}

void SceneObject::translate(glm::vec3 positionT) {
    // update the instance variables
    Translation += positionT;
}

void SceneObject::scale(glm::vec3 scaleT) {
    // update the instance variables
    Scale *= scaleT;
}

void SceneObject::rotate(glm::vec3 rotationT) {
    // update the instance variables
    rotationX += rotationT.x;
    rotationY += rotationT.y;
    rotationZ += rotationT.z;
}

void SceneObject::setTexture()  {
    ////////////////////////////////////////////////
    //  Diffuse and Ambient Texture
    ////////////////////////////////////////////////
    glGenTextures(1,                  // how many textures we want to generate
                  &scene_objectTextureLoc1);  // the location of the stored texture
    
    // Bind the texture location so any further subsequent texture commands will operate on the bounded object
    glBindTexture(GL_TEXTURE_2D, scene_objectTextureLoc1);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *crateImageData = SOIL_load_image("/Users/nwaters/code/go_stop/assets/metal_container.png",
                                                    &width,
                                                    &height,
                                                    &nrChannels,
                                                    0);
    if (crateImageData)
    {
        // Now that we have loaded the data from an image, we can create the texture
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGBA,
                     width,
                     height,
                     0,
                     GL_RGBA,
                     GL_UNSIGNED_BYTE,
                     crateImageData);
        // Create a minmap of the texture bound to GL_TEXTURE_2D
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    // free the image
    SOIL_free_image_data(crateImageData);
    
    
    ////////////////////////////////////////////////
    //  Specular Texture
    ////////////////////////////////////////////////
    glGenTextures(1,                     // how many textures we want to generate
                  &scene_objectTextureLoc2);  // the location of the stored texture
    
    // Bind the texture location so any further subsequent texture commands will operate on the bounded object
    glBindTexture(GL_TEXTURE_2D, scene_objectTextureLoc2);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // load and generate the texture
    unsigned char *specularMap = SOIL_load_image("/Users/nwaters/code/go_stop/assets/metal_container_specular.png",
                                                 &width,
                                                 &height,
                                                 &nrChannels,
                                                 0);
    if (specularMap)
    {
        // Now that we have loaded the data from an image, we can create the texture
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGBA,
                     width,
                     height,
                     0,
                     GL_RGBA, // it has alpha data, so we need to tell OpenGL that
                     GL_UNSIGNED_BYTE,
                     specularMap);
        // Create a minmap of the texture bound to GL_TEXTURE_2D
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    // free the image
    SOIL_free_image_data(specularMap);
    
    // You MUST activate the shader before assigning uniforms
    scene_objectShader.use();
    // set the uniform values to the correct texture unit
    glUniform1i(glGetUniformLocation(scene_objectShader.ID, "material.ambient"), 0);
    glUniform1i(glGetUniformLocation(scene_objectShader.ID, "material.diffuse"), 0);
    glUniform1i(glGetUniformLocation(scene_objectShader.ID, "material.specular"), 1);
}

glm::vec3 SceneObject::getPosition()  {
    return this->Translation;
}

// ------------------------------------------------------------------------
    // Methods that can be overridden by derived classes
    // ------------------------------------------------------------------------
float * SceneObject::getVertices()  {
    std::cout << "Getting vertices for SceneObject: " << std::endl;
    return DEFAULT_MESH_VERTICES;
}


int SceneObject::getVerticesSize() {
    return sizeof(DEFAULT_MESH_VERTICES);
}

int SceneObject::getSpan() {
    return 8;
}

int SceneObject::getNumVertices() {
    return 3;
}

void SceneObject::resetShader() {
    this->scene_objectShader = this->defaultShader;
}

void SceneObject::setDefaultShader() {
    this->defaultShader = Shader("/Users/nwaters/code/go_stop/go_stop/scene_object/scene_object.vert",
                                 "/Users/nwaters/code/go_stop/go_stop/scene_object/scene_object.frag");
}

Shader SceneObject::getDefaultShader() {
    return this->defaultShader;
}

Material SceneObject::getMaterial() {
    return this->scene_objectMaterial;
}

void SceneObject::setMaterial() {
    int shininessLoc = glGetUniformLocation(scene_objectShader.ID, "material.shininess");
    glUniform1f(shininessLoc, scene_objectMaterial.shininess);
}

void SceneObject::deAllocate() {
    // you must delete the VAO before the EBO.
    glDeleteVertexArrays(1, &scene_objectVAO);
    glDeleteBuffers(1, &scene_objectVBO);
    glDeleteBuffers(1, &scene_objectEBO);
}
