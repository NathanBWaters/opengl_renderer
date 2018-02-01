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
#include "../scene/Scene.hpp"
#include "../scene_object/scene_object.hpp"
#include "../cube/cube.hpp"

class Scene;

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
    void setDefaultShader() override;
    
    /**
     * Sets the textures for the Skybox
     */
    void setTexture() override;
    
    /**
     * Override the parent setShader so it has no effect on the skybox
     */
    void setShader(Shader newShader) override;
    
    void render() override;
};
#endif /* skybox_hpp */
