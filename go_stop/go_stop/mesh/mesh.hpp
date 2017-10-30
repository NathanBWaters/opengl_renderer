//
//  mesh.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef MESH_MODEL_H
#define MESH_MODEL_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include <SOIL.h>

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;
extern glm::vec3 ambientLight;

extern Camera camera;

extern glm::vec3 POINT_LIGHT_POSITION;

class Scene;
class PointLight;

class Mesh
{
public:
    Scene* scene;

    // Starting transformation variables
    glm::vec3 Translation;
    glm::vec3 Scale;

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    
    GLuint meshVBO;
    GLuint meshVAO;
    GLuint meshEBO;
    GLuint meshTextureLoc1;
    GLuint meshTextureLoc2;

    Material meshMaterial;
    
    Shader meshShader;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    float DEFAULT_MESH_VERTICES[15] = {
        // --- position ---   -- textures --
        0.0f,   0.5f,  0.0f,  0.5f,  1.0f,   // top middle
        0.5f,  -0.5f,  0.0f,  1.0f,  0.0f,   // bottom right
        -0.5f,  -0.5f,  0.0f, 0.0f,  0.0f,   // bottom left
    };
    
    /**
     * Constructor generates the shader on the fly
     */
    Mesh(Scene* scene,
         glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));

    void setMaterial();
    
    /**
     * Initializes the Mesh
     */
    void init();
    
    // ------------------------------------------------------------------------
    void render(glm::vec3 positionT = glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3 rotationT = glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3 scaleT = glm::vec3(1.0f, 1.0f, 1.0f));

    /**
     * Sets texture information on the mesh
     */
    void setTexture();
    
    /**
     * Sets the lighting information from the scene onto mesh
     */
    void setLights();
    
    glm::vec3 getPosition();
    
    // ------------------------------------------------------------------------
    // Methods that can be overridden by derived classes
    // ------------------------------------------------------------------------
    void addToScene();

    virtual float * getVertices();
    
    virtual int getVerticesSize();
    
    virtual int getSpan();
    
    virtual int getNumVertices();

    virtual Shader getShader();
    
    virtual Material getMaterial();
    
    void deAllocate();
};

#endif /* mesh_hpp */

