//
//  point_light.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include <iostream>

#include "../scene/Scene.hpp"
#include "../cube/cube.hpp"
#include "point_light.hpp"

PointLight::PointLight(Scene* scene,
                       glm::vec3 color,
                       glm::vec3 position,
           			   glm::vec3 rotation,
           			   glm::vec3 scale) :
        Cube(scene, position, rotation, scale) {
	std::cout << "Making a PointLight" << std::endl;
    this->color = color;
    this->addLightToScene();
}
    
void PointLight::addLightToScene() {
    std::cout << "ADDING THE POINT LIGHT TO THE SCENE" << std::endl;
    this->scene->addLight(this);
}

glm::vec3 PointLight::getLightColor() {
    return this->color;
}

void PointLight::setMaterial() {
    int lightColorLoc = glGetUniformLocation(scene_objectShader.ID, "lightColor");
    glm::vec3 lightColor = this->getLightColor();
    glUniform4f(lightColorLoc, lightColor.r, lightColor.g, lightColor.b, 1.0);
}

void PointLight::setDefaultShader() {
    this->defaultShader = Shader("/Users/nwaters/code/go_stop/go_stop/go_stop/point_light/point_light.vert",
                                 "/Users/nwaters/code/go_stop/go_stop/go_stop/point_light/point_light.frag");
}
