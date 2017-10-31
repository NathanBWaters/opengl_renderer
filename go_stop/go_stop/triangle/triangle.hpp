//
//  triangle.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef TRIANGLE_MODEL_H
#define TRIANGLE_MODEL_H

#include "../mesh/mesh.hpp"

class Triangle : public Mesh
{
private:
    float TRIANGLE_VERTICES[24] = {
        // --- position ---   -- textures --  --- normals ---
        0.0f,   0.5f,  0.0f,  0.5f,  1.0f,   0.0f, 0.0f, 1.0f,   // top middle
        0.5f,  -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f, 1.0f,   // bottom right
        -0.5f,  -0.5f,  0.0f, 0.0f,  0.0f,   0.0f, 0.0f, 1.0f   // bottom left
    };

public:
    Triangle(Scene* scene,
             glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
             glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
             glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
    
    float * getVertices();
    
    int getNumVertices();
    
};

#endif /* triangle_hpp */
