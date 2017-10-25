//
//  mesh.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/24/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "mesh.hpp"


void Mesh::setTexture() {
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
