//
//  Material.hpp
//  go_stop
//
//  Created by Nathan Waters on 10/22/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <glm/glm.hpp>

struct Material {
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    GLfloat shininess;
};

#endif /* Material_hpp */
