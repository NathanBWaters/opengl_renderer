//
//  framebuffer.hpp
//  go_stop
//
//  Created by Nathan Waters on 11/21/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef framebuffer_hpp
#define framebuffer_hpp

#include <stdio.h>
#include "../mesh/mesh.hpp"

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;

class FrameBuffer
{
    
public:
    // reference to the Framebuffer object
    unsigned int framebuffer;
private:
    float FRAME_BUFFER_VERTICES[48] = {
        // --- position ---   -- textures --  --- normals ---
        0.5f,   0.5f,  0.0f,  1.0f,  1.0f,   0.0f, 0.0f, 1.0f,   // top right
        -0.5f,  -0.5f,  0.0f, 0.0f,  0.0f,   0.0f, 0.0f, 1.0f,   // bottom left
        0.5f,  -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f, 1.0f,   // bottom right
        0.5f,   0.5f,  0.0f,  1.0f,  1.0f,   0.0f, 0.0f, 1.0f,   // top right
        -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f, 1.0f,   // top left
        -0.5f,  -0.5f,  0.0f, 0.0f,  0.0f,   0.0f, 0.0f, 1.0f    // bottom left
    };
    
    unsigned int span = 8;
    unsigned int numVertices = 6;
    
    // reference to the texture attachment that stores the color data to be sampled
    unsigned int textureColorBuffer;
    
    // reference to the Renderbuffer object.  Used for storing stencil and depth data.
    unsigned int renderbuffer;
    
    GLuint frameBufferPlaneVBO;
    GLuint frameBufferPlaneVAO;
    
    Shader currentShader;
    Shader defaultShader;
    
public:
    FrameBuffer(int width = SCREEN_WIDTH,
                int height = SCREEN_HEIGHT);
    
    /**
     * Creates the plane that spans the screen and is used to display to color information
     * stored in the off-screen framebuffer
     */
    void createPlane();
    
    /**
     * Creates the default shader, which does not use any post-processing effect on the frame
     */
    void createDefaultShader();
    
    /**
     * Renders the plane that will visualize the scene which has been written to the off-screen
     * framebuffer
     */
    void render();
};

#endif /* framebuffer_hpp */
