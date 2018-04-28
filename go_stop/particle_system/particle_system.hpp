//
//  ParticleSystem.hpp
//  go_stop
//
//  Created by Nathan Waters on 2/19/18.
//  Copyright © 2018 Nathan Waters. All rights reserved.
//


#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <OpenGL/gl3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <glm/glm.hpp>
#include <QOpenGLFunctions>

#include "../Shader.hpp"
#include "../scene_object/scene_object.hpp"
#include "../particle/particle.hpp"

using namespace std;

class ParticleSystem : public SceneObject
{
private:
    int maxParticles = 500;

    // list of particles in the ParticleSystem
    std::vector<Particle> particles;

    // the vertex data for the particles.  Just two triangles
    GLuint billboardVBO;

    // the dynamic particle data such as the position
    GLuint particleDynamicVBO;

    // the static particle data such as the color
    GLuint particleStaticVBO;
public:
    ParticleSystem(Scene* scene,
                   glm::vec3 position,
                   glm::vec3 rotation,
                   glm::vec3 scale,
                   int numParticles);

    void generateParticles();

    void init() override;

    void setLights() override;

    void render() override;

    void setDefaultShader() override;
};
#endif

