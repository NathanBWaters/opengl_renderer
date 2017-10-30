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
    
    Scene();
    
    void addItem(Mesh* mesh);
    
    void addLight(PointLight* light);
    
    std::vector<PointLight> getLights();
    
    void initialize();
    
    void render();
};

#endif /* scene_hpp */
