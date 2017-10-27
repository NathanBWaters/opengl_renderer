//
//  point_light.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "point_light.hpp"

PointLight::PointLight(glm::vec3 position,
           			   glm::vec3 rotation,
           			   glm::vec3 scale) :
        Cube(position, rotation, scale) {
	std::cout << "Making a PointLight" << std::endl;
}
    
/**
 * Returns the shader for the light, which makes it white
 */
Shader PointLight::getShader() {
    return Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/point_light/point_light.vert",
                  "/Users/nwaters/code/go_stop/go_stop/go_stop/point_light/point_light.frag");
}
