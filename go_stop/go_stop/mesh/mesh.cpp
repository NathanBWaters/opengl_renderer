//
//  mesh.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/24/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "mesh.hpp"
#include "../scene/Scene.hpp"

Mesh::Mesh(glm::vec3 position,
           glm::vec3 rotation,
           glm::vec3 scale) {
    Translation = position;
    Scale = scale;
    
    this->rotationX = rotation.x;
    rotationY = rotation.y;
    rotationZ = rotation.z;
    
    // white plastic
    this->meshMaterial = Material{
        glm::vec3(0.2f, 0.2f, 0.2f),     // ambient
        glm::vec3(0.55f, 0.55f, 0.55f),  // diffuse
        glm::vec3(1.7f, 1.7f, 1.7f),     // specular
        32.0f,                   // shininess
    };
}

void Mesh::setMaterial() {
    int shininessLoc = glGetUniformLocation(meshShader.ID, "material.shininess");
    glUniform1f(shininessLoc, meshMaterial.shininess);
}

void Mesh::init() {
    meshShader = getShader();
    
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float * vertices = getVertices();
    int verticesSize = getVerticesSize();
    std::cout << "getNumVertices() * getSpan() * sizeof(float): " << getNumVertices() * getSpan() * sizeof(float) << std::endl;
    std::cout << "verticesSize: " << verticesSize << std::endl;
    glGenVertexArrays(1, &meshVAO);
    glGenBuffers(1, &meshVBO);
    
    // VAO
    // You bind the Vertex Array Object first, then bind and set vertex buffer(s), and then
    // configure vertex attributes(s).
    glBindVertexArray(meshVAO);
    
    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, meshVBO);
    
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
    
    // texture position, location == 1, span 2
    glVertexAttribPointer(1,                          // location in vertex shader
                          2,                          // number of vertices for texture value
                          GL_FLOAT,                   // data type
                          GL_FALSE,                   //
                          getSpan() * sizeof(float),          // span of one vertex
                          (void*)(3* sizeof(float))); // where on the vertex does it start
    glEnableVertexAttribArray(1);                     // location of position
    
    // normals vertex, location == 2, span 3
    glVertexAttribPointer(2,                          // location in vertex shader
                          3,                          // number of vertices for normal vector
                          GL_FLOAT,                   // data type
                          GL_FALSE,                   //
                          getSpan() * sizeof(float),  // span of one vertex
                          (void*)(5* sizeof(float))); // where on the vertex does it start
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
    projectionMatrix = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
}

void Mesh::setLights() {
//    std::vector<PointLight> scenePointLights = this->scene->getLights();

    int numPointLightsLoc = glGetUniformLocation(meshShader.ID, "NUM_POINT_LIGHTS");
    glUniform1i(numPointLightsLoc, 1);
    
    // Set ambient light
    int ambientLightLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].ambient");
    glUniform3f(ambientLightLoc, ambientLight.x, ambientLight.y, ambientLight.z);
    
    glm::vec3 whiteLight = glm::vec3(1.0f, 1.0f, 1.0f);

    // Set specular light
    int specularLightLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].specular");
    glUniform3f(specularLightLoc, whiteLight.x, whiteLight.y, whiteLight.z);
    
    // Set diffuse light
    int diffuseLightLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].diffuse");
    glUniform3f(diffuseLightLoc, whiteLight.x, whiteLight.y, whiteLight.z);
    
    // Set point light 1 position
    int pointLightLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].position");
    glUniform3f(pointLightLoc, POINT_LIGHT_POSITION.x, POINT_LIGHT_POSITION.y, POINT_LIGHT_POSITION.z);
    
    // Set attenuation constants
    int lightConstantLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].constant");
    glUniform1f(lightConstantLoc, 1.0f);

    int lightLinearLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].linear");
    glUniform1f(lightLinearLoc, 0.09f);

    int lightQuadraticLoc = glGetUniformLocation(meshShader.ID, "pointLights[0].quadratic");
    glUniform1f(lightQuadraticLoc, 0.032f);
}

void Mesh::render(glm::vec3 positionT,
                  glm::vec3 rotationT,
                  glm::vec3 scaleT)
{
    meshShader.use();
    
    // update the instance variables
    Translation += positionT;
    Scale *= scaleT;
    rotationX += rotationT.x;
    rotationY += rotationT.y;
    rotationZ += rotationT.z;
    
    glm::mat4 scalingMatrix = glm::scale(glm::mat4(), Scale);
    
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(), rotationX, glm::vec3(1.0f, 0.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotationY, glm::vec3(0.0f, 1.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotationZ, glm::vec3(0.0f, 0.0f, 1.0f));
    
//    std::cout << glm::to_string(rotationMatrix) << std::endl;
    glm::mat4 translationMatrix = glm::translate(glm::mat4(), Translation);
    
    glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;
    
    // Set viewMatrix position (which is the camera position)
    int viewPositionLoc = glGetUniformLocation(meshShader.ID, "viewPosition");
    glUniform3f(viewPositionLoc, camera.Position.x, camera.Position.y, camera.Position.z);
    
    // Set the model matrix (where the mesh is in world space)
    int modelMatrixLoc = glGetUniformLocation(meshShader.ID, "modelMatrix");
    glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    
    // Set view matrix
    int viewMatrixLoc = glGetUniformLocation(meshShader.ID, "viewMatrix");
    glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
    
    // Set projection matrix
    int projectionMatrixLoc = glGetUniformLocation(meshShader.ID, "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    
    // setting image one, which is on the texture unit GL_TEXTURE0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, meshTextureLoc1);
    // setting image two, which is on the texture unit GL_TEXTURE1
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, meshTextureLoc2);
    
    glBindVertexArray(meshVAO);
    
    // Drawing from the EBO through the VAO.
    glDrawArrays(GL_TRIANGLES, 0, getNumVertices());
}

void Mesh::setTexture()  {
    ////////////////////////////////////////////////
    //  Diffuse and Ambient Texture
    ////////////////////////////////////////////////
    glGenTextures(1,                     // how many textures we want to generate
                  &meshTextureLoc1);  // the location of the stored texture
    
    // Bind the texture location so any further subsequent texture commands will operate on the bounded object
    glBindTexture(GL_TEXTURE_2D, meshTextureLoc1);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *crateImageData = SOIL_load_image("/Users/nwaters/code/go_stop/go_stop/assets/metal_container.png",
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
                  &meshTextureLoc2);  // the location of the stored texture
    
    // Bind the texture location so any further subsequent texture commands will operate on the bounded object
    glBindTexture(GL_TEXTURE_2D, meshTextureLoc2);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // load and generate the texture
    unsigned char *specularMap = SOIL_load_image("/Users/nwaters/code/go_stop/go_stop/assets/metal_container_specular.png",
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
    meshShader.use();
    // set the uniform values to the correct texture unit
    glUniform1i(glGetUniformLocation(meshShader.ID, "material.ambient"), 0);
    glUniform1i(glGetUniformLocation(meshShader.ID, "material.diffuse"), 0);
    glUniform1i(glGetUniformLocation(meshShader.ID, "material.specular"), 1);
}


// ------------------------------------------------------------------------
    // Methods that can be overridden by derived classes
    // ------------------------------------------------------------------------
float * Mesh::getVertices()  {
    std::cout << "Getting vertices for Mesh: " << std::endl;
    return DEFAULT_MESH_VERTICES;
}


int Mesh::getVerticesSize() {
    return sizeof(DEFAULT_MESH_VERTICES);
}

int Mesh::getSpan() {
    return 8;
}

int Mesh::getNumVertices() {
    return 3;
}

Shader Mesh::getShader() {
    return Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/mesh/mesh.vert",
                  "/Users/nwaters/code/go_stop/go_stop/go_stop/mesh/mesh.frag");
}

Material Mesh::getMaterial() {
    return this->meshMaterial;
}

void Mesh::deAllocate() {
    // you must delete the VAO before the EBO.
    glDeleteVertexArrays(1, &meshVAO);
    glDeleteBuffers(1, &meshVBO);
    glDeleteBuffers(1, &meshEBO);
}
