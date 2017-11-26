//
//  skybox.hpp
//  go_stop
//
//  Created by Nathan Waters on 11/24/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef skybox_hpp
#define skybox_hpp

#include <stdio.h>
#include "../cube/cube.hpp"

class Skybox : public Cube
{

public:
    /**
     * Creating a Skybox
     */
    Skybox(Scene* scene);
    
    
    /**
     * Sets the shader for the Skybox
     */
    void setDefaultShader();
    
    /**
     * Sets the textures for the Skybox
     */
    void setTexture();
    
    /**
     * Override the parent setShader so it has no effect on the skybox
     */
    void setShader(Shader newShader);
    
    void render();
};
#endif /* skybox_hpp */
