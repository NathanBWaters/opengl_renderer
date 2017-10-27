//
//  Scene.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/22/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "../mesh/mesh.hpp"
#include "../point_light/point_light.hpp"
#include "Scene.hpp"

Scene::Scene()
{
    std::cout << "Creating scene " << std::endl;
}

void Scene::addItem(Mesh* mesh) {
    std::cout << "Adding mesh " << std::endl;
    sceneItems.push_back(*mesh);
}

void Scene::addLight(PointLight* light) {
    std::cout << "Adding light " << std::endl;
    lights.push_back(*light);
}

std::vector<PointLight> Scene::getLights() {
    return this->lights;
}
