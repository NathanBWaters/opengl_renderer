//
//  Scene.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/22/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "Scene.hpp"
#include "../mesh/mesh.hpp"
#include "../point_light/point_light.hpp"


Scene::Scene()
{
    std::cout << "Creating scene " << std::endl;
}

void Scene::addItem(Mesh* mesh) {
    this->sceneItems.push_back(mesh);
}

void Scene::addLight(PointLight* light) {
    lights.push_back(light);
}

void Scene::initialize() {
    for ( auto item : this->sceneItems )
    {
        item->init();
    }
}

void Scene::render() {
    for ( auto item : sceneItems )
    {
        item->render();
    }
}

std::vector<PointLight*> Scene::getLights() {
    return this->lights;
}

void Scene::deAllocate() {
    for ( auto item : sceneItems )
    {
        item->deAllocate();
    }
}
