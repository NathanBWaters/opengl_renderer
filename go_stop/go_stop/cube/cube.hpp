//
//  cube.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "../mesh/mesh.hpp"

class Cube : public Mesh
{
private:
    float CUBE_VERTICES[288] = {
        // ---- vertex ----  -- texture --   ----- normals -----
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,    0.0f,  0.0f, -1.0f,  // Back Face
        0.5f,  0.5f,  -0.5f,  1.0f, 1.0f,    0.0f,  0.0f, -1.0f,  //
        0.5f, -0.5f,  -0.5f,  1.0f, 0.0f,    0.0f,  0.0f, -1.0f,  //
        0.5f,  0.5f,  -0.5f,  1.0f, 1.0f,    0.0f,  0.0f, -1.0f,  //
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,    0.0f,  0.0f, -1.0f,  //
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,    0.0f,  0.0f, -1.0f,  //
        
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,    0.0f,  0.0f, 1.0f,   // Front Face
        0.5f,  -0.5f,  0.5f,  1.0f, 0.0f,    0.0f,  0.0f, 1.0f,   //
        0.5f,   0.5f,  0.5f,  1.0f, 1.0f,    0.0f,  0.0f, 1.0f,   //
        0.5f,   0.5f,  0.5f,  1.0f, 1.0f,    0.0f,  0.0f, 1.0f,   //
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,    0.0f,  0.0f, 1.0f,   //
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,    0.0f,  0.0f, 1.0f,   //
        
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   -1.0f,  0.0f,  0.0f,  // Left Face
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   -1.0f,  0.0f,  0.0f,  //
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   -1.0f,  0.0f,  0.0f,  //
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   -1.0f,  0.0f,  0.0f,  //
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   -1.0f,  0.0f,  0.0f,  //
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   -1.0f,  0.0f,  0.0f,  //
        
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,     1.0f,  0.0f,  0.0f,  // Right Face
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,     1.0f,  0.0f,  0.0f,  //
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,     1.0f,  0.0f,  0.0f,  //
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,     1.0f,  0.0f,  0.0f,  //
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,     1.0f,  0.0f,  0.0f,  //
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,     1.0f,  0.0f,  0.0f,  //
        
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,    0.0f, -1.0f,  0.0f,  // Bottom Face
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,    0.0f, -1.0f,  0.0f,   //
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,    0.0f, -1.0f,  0.0f,   //
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,    0.0f, -1.0f,  0.0f,   //
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,    0.0f, -1.0f,  0.0f,  //
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,    0.0f, -1.0f,  0.0f,  //
        
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,    0.0f,  1.0f,  0.0f,  // Top Face
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,    0.0f,  1.0f,  0.0f,   //
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,    0.0f,  1.0f,  0.0f,   //
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,    0.0f,  1.0f,  0.0f,   //
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,    0.0f,  1.0f,  0.0f,  //
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,    0.0f,  1.0f,  0.0f,  //
    };

public:
    Cube(Scene* scene,
         glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
    
    float * getVertices();
    
    int getNumVertices();
};

#endif /* cube_hpp */
