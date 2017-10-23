//
//  mesh.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef MESH_MODEL_H
#define MESH_MODEL_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include <SOIL.h>

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;
extern glm::vec3 ambientLight;

extern Camera camera;

extern glm::vec3 POINT_LIGHT_POSITION;

class Mesh
{
public:
    // Starting transformation variables
    glm::vec3 Translation;
    glm::vec3 Scale;

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    
    GLuint meshVBO;
    GLuint meshVAO;
    GLuint meshEBO;
    GLuint meshTextureLoc1;
    GLuint meshTextureLoc2;

    Material meshMaterial;
    
    Shader meshShader;

    glm::vec3 tPos;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    float DEFAULT_MESH_VERTICES[15] = {
        // --- position ---   -- textures --
        0.0f,   0.5f,  0.0f,  0.5f,  1.0f,   // top middle
        0.5f,  -0.5f,  0.0f,  1.0f,  0.0f,   // bottom right
        -0.5f,  -0.5f,  0.0f, 0.0f,  0.0f,   // bottom left
    };
    
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Mesh(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f))
    {
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
            128.0f,                   // shininess
        };
    }
    
    void init() {
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
    
        // Set ambient light
        int ambientLightLoc = glGetUniformLocation(meshShader.ID, "ambientLight");
        glUniform3f(ambientLightLoc, ambientLight.x, ambientLight.y, ambientLight.z);
        
        // Set point light 1 position
        int pointLightLoc = glGetUniformLocation(meshShader.ID, "pointLightPosition1");
        glUniform3f(pointLightLoc, POINT_LIGHT_POSITION.x, POINT_LIGHT_POSITION.y, POINT_LIGHT_POSITION.z);

        
        std::cout<<glm::to_string(camera.Position)<<std::endl;
        
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
    
    // ------------------------------------------------------------------------
    void render(glm::vec3 positionT = glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3 rotationT = glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3 scaleT = glm::vec3(1.0f, 1.0f, 1.0f))
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
        
        std::cout << glm::to_string(rotationMatrix) << std::endl;
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
    
    void setTexture() {
        ////////////////////////////////////////////////
        //  Texture 1
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
        unsigned char *crateImageData = SOIL_load_image("/Users/nwaters/code/go_stop/go_stop/assets/container.jpg",
                                                        &width,
                                                        &height,
                                                        &nrChannels,
                                                        0);
        if (crateImageData)
        {
            // Now that we have loaded the data from an image, we can create the texture
            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         width,
                         height,
                         0,
                         GL_RGB,
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
        //  Texture 2
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
        unsigned char *awesomeFaceData = SOIL_load_image("/Users/nwaters/code/go_stop/go_stop/assets/awesomeface.png",
                                                         &width,
                                                         &height,
                                                         &nrChannels,
                                                         0);
        if (awesomeFaceData)
        {
            // Now that we have loaded the data from an image, we can create the texture
            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         width,
                         height,
                         0,
                         GL_RGBA, // it has alpha data, so we need to tell OpenGL that
                         GL_UNSIGNED_BYTE,
                         awesomeFaceData);
            // Create a minmap of the texture bound to GL_TEXTURE_2D
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        // free the image
        SOIL_free_image_data(awesomeFaceData);
        
        // You MUST activate the shader before assigning uniforms
        meshShader.use();
        // set the uniform values to the correct texture unit
        glUniform1i(glGetUniformLocation(meshShader.ID, "meshTexture1"), 0);
        glUniform1i(glGetUniformLocation(meshShader.ID, "meshTexture2"), 1);
    }
    
    void setMaterial() {
        int ambientLoc = glGetUniformLocation(meshShader.ID, "material.ambient");
        glUniform3f(ambientLoc, meshMaterial.ambient.x, meshMaterial.ambient.y, meshMaterial.ambient.z);
        
        int diffuseLoc = glGetUniformLocation(meshShader.ID, "material.diffuse");
        glUniform3f(diffuseLoc, meshMaterial.diffuse.x, meshMaterial.diffuse.y, meshMaterial.diffuse.z);
        
        int specularLoc = glGetUniformLocation(meshShader.ID, "material.specular");
        glUniform3f(specularLoc, meshMaterial.specular.x, meshMaterial.specular.y, meshMaterial.specular.z);

        int shininessLoc = glGetUniformLocation(meshShader.ID, "material.shininess");
        glUniform1f(shininessLoc, meshMaterial.shininess);
    }
    
    // ------------------------------------------------------------------------
    // Methods that can be overridden by derived classes
    // ------------------------------------------------------------------------
    virtual float * getVertices() {
        std::cout << "Getting vertices for Mesh: " << std::endl;
        return DEFAULT_MESH_VERTICES;
    }
    
    virtual int getVerticesSize() {
        return sizeof(DEFAULT_MESH_VERTICES);
    }
    
    virtual int getSpan() {
        return 8;
    }
    
    virtual int getNumVertices() {
        return 3;
    }

    virtual Shader getShader() {
        return Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/mesh/mesh.vert",
                      "/Users/nwaters/code/go_stop/go_stop/go_stop/mesh/mesh.frag");
    }
    
    virtual Material getMaterial() {
        return this->meshMaterial;
    }
    
    void deAllocate() {
        // you must delete the VAO before the EBO.
        glDeleteVertexArrays(1, &meshVAO);
        glDeleteBuffers(1, &meshVBO);
        glDeleteBuffers(1, &meshEBO);
    }
};

#endif /* mesh_hpp */

