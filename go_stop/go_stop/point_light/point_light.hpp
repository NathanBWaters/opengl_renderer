//
//  point_light.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "../cube/cube.hpp"

class Scene;

class PointLight : public Cube
{
private:

public:
    PointLight(Scene* scene,
               glm::vec3 position = POINT_LIGHT_POSITION,
               glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
    
    /**
     * Returns the shader for the light, which makes it white
     */
    Shader getShader();
    
    void addLightToScene();
    
};

#endif /* cube_hpp */
