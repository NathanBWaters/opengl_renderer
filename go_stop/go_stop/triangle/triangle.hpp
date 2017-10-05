//
//  triangle.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef TRIANGLE_MODEL_H
#define TRIANGLE_MODEL_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"
#include "Camera.hpp"
#include <SOIL.h>

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

extern Camera camera;

class Triangle
{
public:
    GLuint triangleVBO;
    GLuint triangleVAO;
    GLuint triangleEBO;
    GLuint triangleTextureLoc1;
    GLuint triangleTextureLoc2;
    Shader triangleShader;
    glm::vec3 tPos;
    glm::mat4 modelMatrix;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Triangle(const glm::vec3 position)
    {
        triangleShader = Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/triangle/triangle.vert",
                                "/Users/nwaters/code/go_stop/go_stop/go_stop/triangle/triangle.frag");
        
        tPos = position;
        
        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
            // --- position ---   ---- colors ----   - textures -
            0.0f,   0.5f,  0.0f,  0.2f, 0.3f, 0.9f,  0.5f,  1.0f, // top middle
            0.5f,  -0.5f,  0.0f,  0.4f, 0.8f, 0.5f,  1.0f,  0.0f,// bottom right
            -0.5f,  -0.5f,  0.0f,  0.2f, 0.4f, 0.3f, 0.0f,  0.0f, // bottom left
        };
        unsigned int indices[] = {  // note that we start from 0!
            0, 1, 2,  // first Triangle
        };
        glGenVertexArrays(1, &triangleVAO);
        glGenBuffers(1, &triangleVBO);
        glGenBuffers(1, &triangleEBO);
        
        std::cout << "triangleVBO: " << triangleVBO << std::endl;
        std::cout << "GL_MAX_VERTEX_ATTRIBS: " << GL_MAX_VERTEX_ATTRIBS << std::endl;
        
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(triangleVAO);
        
        // VBO
        glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        // EBO
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        
        // position, location == 0
        glVertexAttribPointer(0,                 // location position
                              3,                 // number of vertices for positional value
                              GL_FLOAT,          // data type
                              GL_FALSE,          //
                              8 * sizeof(float), // span of one vertex
                              (void*)0);         // where on the vertex does it start
        // you must enable to position of the vertex location of position.  You can see the size of the
        // vertex attribut array by calling GL_MAX_VERTEX_ATTRIBS.  They are disabled by default.
        glEnableVertexAttribArray(0);
        
        
        // color, location == 1
        glVertexAttribPointer(1,                          // location position
                              3,                          // number of vertices for positional value
                              GL_FLOAT,                   // data type
                              GL_FALSE,                   //
                              8 * sizeof(float),          // span of one vertex
                              (void*)(3* sizeof(float))); // where on the vertex does it start
        glEnableVertexAttribArray(1);                     // location of position
        
        // texture position, location == 2
        glVertexAttribPointer(2,                          // location position
                              2,                          // number of vertices for positional value
                              GL_FLOAT,                   // data type
                              GL_FALSE,                   //
                              8 * sizeof(float),          // span of one vertex
                              (void*)(6* sizeof(float))); // where on the vertex does it start
        glEnableVertexAttribArray(2);                     // location of position
        
        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        ////////////////////////////////////////////////
        //  Texture 1
        ////////////////////////////////////////////////
        glGenTextures(1,                     // how many textures we want to generate
                      &triangleTextureLoc1);  // the location of the stored texture
        
        // Bind the texture location so any further subsequent texture commands will operate on the bounded object
        glBindTexture(GL_TEXTURE_2D, triangleTextureLoc1);
        
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
                      &triangleTextureLoc2);  // the location of the stored texture
        
        // Bind the texture location so any further subsequent texture commands will operate on the bounded object
        glBindTexture(GL_TEXTURE_2D, triangleTextureLoc2);
        
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
        triangleShader.use();
        // set the uniform values to the correct texture unit
        glUniform1i(glGetUniformLocation(triangleShader.ID, "triangleTexture1"), 0);
        glUniform1i(glGetUniformLocation(triangleShader.ID, "triangleTexture2"), 1);

        
        // Unbind the VBO and VAO at the end, but not the EBO because it's part of the VAO.
        
        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens.
        // Modifying other VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs)
        // when it's not directly necessary.
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        
        // Model Matrix to convert local vertices to world space.  Save this->modelMatrix
        glm::mat4 model;
        modelMatrix = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        
        // View Matrix to convert world space to view space
        glm::mat4 view;
        viewMatrix = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
        
        // Projection Matrix to convert view space to clip space
        glm::mat4 projection;
        projectionMatrix = glm::perspective(50.0f, 1.0f, 0.1f, 100.0f);
    }

    // ------------------------------------------------------------------------
    void render()
    {
        triangleShader.use();
        
        // Let's keep it constantly rotating by rotating the model matrix
        modelMatrix = glm::rotate(modelMatrix, glm::radians(1.0f), glm::vec3(1.0f, 1.0f, 0.0f));

        // Set model matrix
        int modelMatrixLoc = glGetUniformLocation(triangleShader.ID, "modelMatrix");
        glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        
        // Set view matrix
        int viewMatrixLoc = glGetUniformLocation(triangleShader.ID, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
        
        // Set projection matrix
        int projectionMatrixLoc = glGetUniformLocation(triangleShader.ID, "projectionMatrix");
        glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
        
        
        // setting image one, which is on the texture unit GL_TEXTURE0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, triangleTextureLoc1);
        // setting image two, which is on the texture unit GL_TEXTURE1
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, triangleTextureLoc2);
        
        glBindVertexArray(triangleVAO);
        
        // Drawing from the EBO through the VAO.
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    }
    
    void deAllocate() {
        // you must delete the VAO before the EBO.
        glDeleteVertexArrays(1, &triangleVAO);
        glDeleteBuffers(1, &triangleVBO);
        glDeleteBuffers(1, &triangleEBO);
    }
};

#endif /* triangle_hpp */
