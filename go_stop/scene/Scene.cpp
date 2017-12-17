//
//  Scene.cpp
//  go_stop
//
//  Created by Nathan Waters on 9/22/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include <QDebug>

#include "Scene.hpp"
#include "../scene_object/scene_object.hpp"
#include "../point_light/point_light.hpp"


Scene::Scene(glm::vec3 ambientLight)
{
    std::cout << "Creating scene " << std::endl;
    this->ambientLight_ = ambientLight;
}

void Scene::addItem(SceneObject* scene_object) {
    this->sceneItems.push_back(scene_object);
}

void Scene::addLight(PointLight* light) {
    lights.push_back(light);
}

glm::vec3 Scene::getAmbientLight() {
    return this->ambientLight_;
}

void Scene::setAmbientLight(glm::vec3 updatedAmbientLight) {
    this->ambientLight_ = updatedAmbientLight;
}

void Scene::initialize() {
    for ( auto item : this->sceneItems )
    {
        item->init();
    }
}

/*
 * Scales all objects in the scene
 */
void Scene::scale(glm::vec3 scaleT) {
    for ( auto item : this->sceneItems )
    {
        item->scale(scaleT);
    }
}

/*
 * Sets all items in the scene to the default shader
 */
void Scene::resetShader() {
    for ( auto item : this->sceneItems )
    {
        item->resetShader();
    }
}

/*
 * Scales all objects in the scene
 */
void Scene::setShader(Shader newShader) {
    for ( auto item : this->sceneItems )
    {
        item->setShader(newShader);
    }
}

/*
 * Rotates all objects in the scene
 */
void Scene::rotate(glm::vec3 rotationT) {
    for ( auto item : this->sceneItems )
    {
        item->rotate(rotationT);
    }
}

void Scene::render() {
    qDebug() << "In render";
    qDebug() << "Size: " << this->sceneItems.size();
    qDebug() << "Max Size: " << this->sceneItems.max_size();
    qDebug() << "Is empty: " << this->sceneItems.empty();
    qDebug() << "address: " << &this->sceneItems[0];
    for ( auto item : this->sceneItems )
    {
        qDebug() << "Rendering 1 item";
        item->render();
        qDebug() << "Rendered";
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
