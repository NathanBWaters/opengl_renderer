//
//  Particle.hpp
//  go_stop
//
//  Created by Nathan Waters on 2/19/18.
//  Copyright © 2018 Nathan Waters. All rights reserved.
//


#ifndef PARTICLE_H
#define PARTICLE_H

#include <OpenGL/gl3.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
using namespace std;

struct Particle{
    glm::vec3 position;             // the position
    glm::vec3 velocity;             // the velocity
    glm::vec4 color;                // rgba color 
    float size;
    float angle;
    float weight;
    float life; // Remaining life of the particle. if < 0 : dead and unused
    float cameradistance; // *Squared* distance to the camera. if dead : -1.0f

    bool operator<(const Particle& that) const {
        // Sort in reverse order : far particles drawn first.
        return this->cameradistance > that.cameradistance;
    }
};

#endif /* PARTICLE_H */
