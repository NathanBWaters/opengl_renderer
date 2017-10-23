//
//  cube.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

extern glm::vec3 POINT_LIGHT_POSITION;

class PointLight : public Cube
{
private:

public:
    PointLight(glm::vec3 position = POINT_LIGHT_POSITION,
               glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
        Cube(position, rotation, scale)
    {
        std::cout << "Making a PointLight" << std::endl;
    }
    
    Shader getShader() {
        return Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/point_light/point_light.vert",
                      "/Users/nwaters/code/go_stop/go_stop/go_stop/point_light/point_light.frag");
    }
    
};

#endif /* cube_hpp */
