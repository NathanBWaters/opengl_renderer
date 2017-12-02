//
//  scene_object.hpp
//  go_stop
//
//  Created by Nathan Waters on 9/17/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

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

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;
extern glm::vec3 ambientLight;

extern Camera camera;

extern glm::vec3 POINT_LIGHT_POSITION;

class Scene;
class PointLight;

class SceneObject
{
public:
    Scene* scene;

    // Starting transformation variables
    glm::vec3 Translation;
    glm::vec3 Scale;

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    
    GLuint scene_objectVBO;
    GLuint scene_objectVAO;
    GLuint scene_objectEBO;
    GLuint scene_objectTextureLoc1;
    GLuint scene_objectTextureLoc2;

    Material scene_objectMaterial;
    
    Shader scene_objectShader;
    
    Shader defaultShader;

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
    SceneObject(Scene* scene,
         glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
    
    /**
     * Initializes the SceneObject
     */
    virtual void init();
    
    // ------------------------------------------------------------------------
    virtual void render(glm::vec3 positionT = glm::vec3(0.0f, 0.0f, 0.0f),
                        glm::vec3 rotationT = glm::vec3(0.0f, 0.0f, 0.0f),
                        glm::vec3 scaleT = glm::vec3(1.0f, 1.0f, 1.0f));

    /**
     * Sets texture information on the scene_object
     */
    virtual void setTexture();
    
    /**
     * Translates the object
     */
    void translate(glm::vec3 positionT);
    
    /**
     * Scales the object
     */
    void scale(glm::vec3 scaleT);
    
    /**
     * Rotates the object
     */
    void rotate(glm::vec3 rotationT);
    
    glm::vec3 getPosition();
    
    void setLights();

    virtual void setShader(Shader newShader);
    
    /**
     * Resets the shader to the default shader
     */
    void resetShader();
    
    Shader getShader();
    
    // ------------------------------------------------------------------------
    // Methods that can be overridden by derived classes
    // ------------------------------------------------------------------------
    void addToScene();

    virtual float * getVertices();
    
    virtual int getVerticesSize();
    
    virtual int getSpan();
    
    virtual int getNumVertices();

    virtual void setDefaultShader();
    
    virtual Shader getDefaultShader();
    
    virtual Material getMaterial();
    
    /**
     * Sets the look of the object
     */
    virtual void setMaterial();
    
    void deAllocate();
};

#endif /* scene_object_hpp */

