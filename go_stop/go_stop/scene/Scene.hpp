//
//  Scene.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/22/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef SCENE_H
#define SCENE_H

class Mesh;
class PointLight;

class Scene
{
public:
    std::vector<Mesh> sceneItems = {};
    std::vector<PointLight> lights = {};
    
    Scene()
    {
        std::cout << "Creating scene " << std::endl;
    }
    
    void addItem(Mesh* mesh) {
        std::cout << "Adding mesh " << std::endl;
        sceneItems.push_back(*mesh);
    }
    
    void addLight(PointLight* light) {
        std::cout << "Adding light " << std::endl;
        lights.push_back(*light);
    }
    
    std::vector<PointLight> getLights() {
        return this->lights;
    }
};

#endif /* scene_hpp */
