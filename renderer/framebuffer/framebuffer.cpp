//
//  framebuffer.cpp
//  go_stop
//
//  Created by Nathan Waters on 11/21/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "framebuffer.hpp"

FrameBuffer::FrameBuffer(int screen_width, int screen_height)
{
    std::cout << "Making a FrameBuffer" << std::endl;
    this->createDefaultShader();

    // Create the FrameBuffer
    glGenFramebuffers(1, &this->framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, this->framebuffer);
    
    // Create the texture attachment that we will be writing to
    glGenTextures(1, &this->textureColorBuffer);
    glBindTexture(GL_TEXTURE_2D, this->textureColorBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, screen_width, screen_height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Now that we’ve created a texture the last thing we need to do is actually attach it to the framebuffer
    glFramebufferTexture2D(GL_FRAMEBUFFER,           // target: the framebuffer type we’re targeting (draw/read).
                           GL_COLOR_ATTACHMENT0,     // attachment: the type of attachment we’re going to attach
                           GL_TEXTURE_2D,            // textarget: the type of the texture you want to attach.
                           this->textureColorBuffer, // texture: the actual texture to attach.
                           0);                       // level: the mipmap level.
    
    // We also want to make sure OpenGL is able to do depth testing (and optionally stencil testing if you’re into
    // that so we have to make sure to add a depth (and stencil) attachment to the framebuffer as well.
    // Since we’ll only be sampling the color buffer and not the other buffers we can create a renderbuffer object
    // for this purpose.
    glGenRenderbuffers(1, &this->renderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, this->renderbuffer); // make renderbuffer the active renderbuffer
    // We are creating a depth and stencil attachment renderbuffer object so we set its internal format to
    // GL_DEPTH24_STENCIL8 which is enough precision for our purposes.
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, screen_width, screen_height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);   // unbind the renderbuffer
    
    // Then, as a final step before we can complete the framebuffer, we attach the renderbuffer object to the
    // depth and stencil attachment of the framebuffer
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_DEPTH_STENCIL_ATTACHMENT,
                              GL_RENDERBUFFER,
                              this->renderbuffer);
    
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    }
    
    // unbind the off-screen framebuffer to return it back to the default framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
    this->createPlane();
}

void FrameBuffer::createPlane() {
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    glGenVertexArrays(1, &this->frameBufferPlaneVAO); // create VAO
    glGenBuffers(1, &this->frameBufferPlaneVBO);      // create VBO
    
    // VAO
    // You bind the Vertex Array Object first, then bind and set vertex buffer(s), and then
    // configure vertex attributes(s).
    glBindVertexArray(this->frameBufferPlaneVAO);
    
    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, this->frameBufferPlaneVBO);
    
    glBufferData(GL_ARRAY_BUFFER,
                 this->numVertices * this->span * sizeof(float),
                 this->FRAME_BUFFER_VERTICES,
                 GL_STATIC_DRAW);
    
    // vertices position, location == 0, span 3
    glVertexAttribPointer(0,                 // location in vertex shader
                          3,                 // number of vertices for positional value
                          GL_FLOAT,          // data type
                          GL_FALSE,          //
                          this->span * sizeof(float), // span of one vertex data
                          (void*)0);         // where on the vertex does it start
    // you must enable to position of the vertex location of position.  You can see the size of the
    // vertex attribut array by calling GL_MAX_VERTEX_ATTRIBS.  They are disabled by default.
    glEnableVertexAttribArray(0);
    
    // texture position, location == 1, span 2
    glVertexAttribPointer(1,                          // location in vertex shader
                          2,                          // number of vertices for texture value
                          GL_FLOAT,                   // data type
                          GL_FALSE,                   //
                          this->span * sizeof(float),          // span of one vertex
                          (void*)(3* sizeof(float))); // where on the vertex does it start
    glEnableVertexAttribArray(1);                     // location of position
    
    // normals vertex, location == 2, span 3
    glVertexAttribPointer(2,                          // location in vertex shader
                          3,                          // number of vertices for normal vector
                          GL_FLOAT,                   // data type
                          GL_FALSE,                   //
                          this->span * sizeof(float),  // span of one vertex
                          (void*)(5* sizeof(float))); // where on the vertex does it start
    glEnableVertexAttribArray(2);                     // location of position
    
    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex
    // attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void FrameBuffer::createDefaultShader() {
    this->defaultShader = Shader("/Users/nwaters/code/go_stop/go_stop/framebuffer/framebuffer.vert",
                                 "/Users/nwaters/code/go_stop/go_stop/framebuffer/framebuffer.frag");
    this->defaultShader.use();
}

void FrameBuffer::render() {
    // activate the framebuffer shader
    this->defaultShader.use();
    
    // bind the frame buffer VAO, key for knowing what to draw with glDrawArrays
    glBindVertexArray(this->frameBufferPlaneVAO);
    
    // set the active texture to 0 unit
    glActiveTexture(GL_TEXTURE0);
    
    // bind the 2D texture to the color buffer
    glBindTexture(GL_TEXTURE_2D, this->textureColorBuffer);
    
    // set the texture to 0 unit
    this->defaultShader.setInt("screenTexture", 0);
    
    // disable depth testing, because we won't need it for the quad
    glDisable(GL_DEPTH_TEST);
    
    // draw the quad
    glDrawArrays(GL_TRIANGLES, 0, this->numVertices);
}
