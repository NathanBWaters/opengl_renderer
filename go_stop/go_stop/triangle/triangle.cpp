//
//  triangle.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "triangle.hpp"

Triangle::Triangle(Scene* scene,
                   glm::vec3 position,
                   glm::vec3 rotation,
                   glm::vec3 scale): 
        Mesh(scene, position, rotation, scale)
{
    std::cout << "Making a Triangle" << std::endl;
}

float * Triangle::getVertices() {
    return TRIANGLE_VERTICES;
}

int Triangle::getNumVertices() {
    return 3;
}
