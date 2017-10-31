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
    std::cout << "Adding mesh " << std::endl;
    this->sceneItems.push_back(mesh);
}

void Scene::addLight(PointLight* light) {
    std::cout << "Adding light " << std::endl;
    lights.push_back(light);
}

void Scene::initialize() {
    std::cout << "Initializing the scene" << std::endl;
    for ( auto item : this->sceneItems )
    {
        std::cout << "Initializing a thing..." << std::endl;
        item->init();
    }
}

void Scene::render() {
    std::cout << "Rendering the scene" << std::endl;
    for ( auto item : sceneItems )
    {
        std::cout << "Rendering a thing..." << std::endl;
        item->render();
    }
}

std::vector<PointLight*> Scene::getLights() {
    return this->lights;
}
