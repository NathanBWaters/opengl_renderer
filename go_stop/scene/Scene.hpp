//
//  Scene.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/22/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "../scene_object/scene_object.hpp"
#include "../point_light/point_light.hpp"

class Scene
{
public:
    std::vector<SceneObject*> sceneItems;
    std::vector<PointLight*> lights;
    
    Scene();
    
    void addItem(SceneObject* scene_object);
    
    void addLight(PointLight* light);
    
    std::vector<PointLight*> getLights();
    
    void scale(glm::vec3 scaleT);
    
    void setShader(Shader newShader);
    
    void resetShader();
    
    void rotate(glm::vec3 rotationT);
    
    void initialize();
    
    void deAllocate();
    
    void render();
};

#endif /* scene_hpp */
