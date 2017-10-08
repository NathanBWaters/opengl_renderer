//
//  triangle.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef TRIANGLE_MODEL_H
#define TRIANGLE_MODEL_H

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
    Triangle(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
             glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
             glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)) : Mesh()
    {
        std::cout << "Making a Triangle" << std::endl;
    }
    
    float * getVertices() {
        return TRIANGLE_VERTICES;
    }
    
    int getNumVertices() {
        return 3;
    }
    
};

#endif /* triangle_hpp */
