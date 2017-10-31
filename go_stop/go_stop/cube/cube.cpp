//
//  cube.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "cube.hpp"

Cube::Cube(Scene* scene,
           glm::vec3 position,
           glm::vec3 rotation,
           glm::vec3 scale) :
    Mesh(scene, position, rotation, scale)
{
    std::cout << "Making a Cube" << std::endl;
}


float * Cube::getVertices() {
    return CUBE_VERTICES;
}

int Cube::getNumVertices() {
    return 36;
}
