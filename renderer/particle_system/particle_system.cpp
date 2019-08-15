//
//  ParticleSystem.cpp
//  go_stop
//
//  Created by Nathan Waters on 2/19/18.
//  Copyright © 2018 Nathan Waters. All rights reserved.
//

#include <stdio.h>
#include "particle_system.hpp"
static const GLfloat PARTICLE_VERTICES[] = {
  -0.5f, -0.5f, 0.0f,
  0.5f,  -0.5f, 0.0f,
  -0.5f, 0.5f,  0.0f,
  0.5f,  0.5f,  0.0f,
};


ParticleSystem::ParticleSystem(Scene* scene,
                               glm::vec3 position,
                               glm::vec3 rotation,
                               glm::vec3 scale,
                               int numParticles) :
    SceneObject(scene, position, rotation, scale),
    particles(numParticles) {
    this->maxParticles = numParticles;
    this->generateParticles();
}

void ParticleSystem::init() {
    std::cout << "-- In init for ParticleSystem" << std::endl;
    setDefaultShader();
    resetShader();

    /*
     * VAO
     */
    // You bind the Vertex Array Object first, then bind and set vertex buffer(s)
    // and then configure vertex attributes(s).
    glGenVertexArrays(1, &scene_objectVAO);
    glBindVertexArray(scene_objectVAO);

    /*
     * Billboard - vertex data for each particle
     */
    // create a buffer for the vertex data for each particle
    glGenBuffers(1, &this->billboardVBO);
    // bind the billboardVBO to the GL_ARRAY_BUFFER to make it active
    glBindBuffer(GL_ARRAY_BUFFER,
                 this->billboardVBO);
    // pass in the vertex data
    glBufferData(GL_ARRAY_BUFFER,
                 this->maxParticles * sizeof(PARTICLE_VERTICES),
                 PARTICLE_VERTICES,
                 GL_STATIC_DRAW);

    /*
     * Dynamic VBO - the dynamic data for particles such as the center of each
     *               particles position.
     */
    glGenBuffers(1, &this->particleDynamicVBO);
    glBindBuffer(GL_ARRAY_BUFFER,
                 this->particleDynamicVBO);
    // we will be passing in the data later
    glBufferData(GL_ARRAY_BUFFER,
                 this->maxParticles * sizeof(GLfloat),
                 NULL,
                 GL_STREAM_DRAW);

    /*
     * Static VBO - the static data for particles, such as the color of each
     *              particle
     */
    glGenBuffers(1, &this->particleStaticVBO);
    glBindBuffer(GL_ARRAY_BUFFER,
                 this->particleStaticVBO);
    // we will be passing in the data later
    glBufferData(GL_ARRAY_BUFFER,
                 this->maxParticles * sizeof(GLfloat),
                 NULL,
                 GL_STREAM_DRAW);


    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,
                 this->billboardVBO);
    glVertexAttribPointer(
        0, // attribute. 0 matches the layout in the shader.
        3, // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0, // stride
        (void*)0 // array buffer offset
    );

    // 2nd attribute buffer : positions of particles' centers
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, this->particleDynamicVBO);
    glVertexAttribPointer(
        1, // attribute. 1 matches the layout in the shader.
        4, // size : x + y + z + size => 4
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0, // stride
        (void*)0 // array buffer offset
    );

    // 3rd attribute buffer : particles' colors
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, this->particleStaticVBO);
    glVertexAttribPointer(
        2, // attribute. 2 matches the layout in the shader.
        4, // size : r + g + b + a => 4
        GL_UNSIGNED_BYTE, // type
        GL_TRUE, // normalized? *** YES, this means that the unsigned char[4] will be accessible with a vec4 (floats) in the shader ***
        0, // stride
        (void*)0 // array buffer offset
    );

    // clean up VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void ParticleSystem::generateParticles() {
    for(int i = 0; i < this->maxParticles; i++) {
        Particle & particle = this->particles[i];
        particle.angle = 0.0f;
        particle.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        particle.position = glm::vec3(0.0f, 0.0f, 0.0f);
        particle.velocity = glm::vec3(0.0f, 0.0f, 0.0f);
        particle.size = 10.0f;
    }
}


void ParticleSystem::setLights() {
    // you don't set lights on a particle system
    // do nothing
}

/**
 * @brief Particle::render
 * Renders the particle system
 */
void ParticleSystem::render() {
    this->scene_objectShader.use();

    setTranslations();

    std::cout << "Rendering ParticleSystem with vao " << scene_objectVAO << std::endl;
    glBindVertexArray(scene_objectVAO);

    // These functions are specific to glDrawArrays*Instanced*.
    // The first parameter is the attribute buffer we're talking about.
    // The second parameter is the "rate at which generic vertex attributes advance when rendering multiple instances"
    // http://www.opengl.org/sdk/docs/man/xhtml/glVertexAttribDivisor.xml
    glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
    glVertexAttribDivisor(1, 1); // positions : one per quad (its center)                 -> 1
    glVertexAttribDivisor(2, 1); // color : one per quad                                  -> 1

    // Draw the particules !
    // This draws many times a small triangle_strip (which looks like a quad).
    // This is equivalent to:
    // for(i in ParticlesCount) : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4), but faster.
    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, maxParticles);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

    // clean up VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void ParticleSystem::setDefaultShader() {
    std::cout << "-- Going to create particle shader" << std::endl;
    this->defaultShader = Shader("/Users/nwaters/code/go_stop/go_stop/particle_system/particle_system.vert",
                                 "/Users/nwaters/code/go_stop/go_stop/particle_system/particle_system.frag");
    std::cout << "-- Tried creating particle shader" << std::endl;
}
