//
//  skybox.cpp
//  go_stop
//
//  Created by Nathan Waters on 11/24/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//

#include "skybox.hpp"


Skybox::Skybox(Scene* scene) : Cube(scene)
{
    std::cout << "Making a Skybox" << std::endl;
}

void Skybox::setDefaultShader() {
    this->defaultShader = Shader("/Users/nwaters/code/go_stop/go_stop/skybox/skybox.vert",
                                 "/Users/nwaters/code/go_stop/go_stop/skybox/skybox.frag");
}

void Skybox::setShader(Shader newShader) {
    // do nothing
}

void Skybox::render(glm::vec3 positionT,
                    glm::vec3 rotationT,
                    glm::vec3 scaleT) {
    this->defaultShader.use();

    glm::mat4 scalingMatrix = glm::scale(glm::mat4(), glm::vec3(5.0f, 5.0f, 5.0f));

    // Set the model matrix (where the scene_object is in world space)
    int modelMatrixLoc = glGetUniformLocation(scene_objectShader.ID, "modelMatrix");
    glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, glm::value_ptr(scalingMatrix));
    
    // Set view matrix
    int viewMatrixLoc = glGetUniformLocation(scene_objectShader.ID, "viewMatrix");

    Camera *camera = this->scene->getCamera();
    glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    
    // Set projection matrix
    int projectionMatrixLoc = glGetUniformLocation(scene_objectShader.ID, "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    
    // setting image one, which is on the texture unit GL_TEXTURE0
    glBindVertexArray(this->scene_objectVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->scene_objectTextureLoc1);
    glDrawArrays(GL_TRIANGLES, 0, this->getNumVertices());
    glBindVertexArray(0);
//    glDepthFunc(GL_LESS); // set depth function back to default
    
    glBindVertexArray(0);
}

void Skybox::setTexture() {
    glGenTextures(1, &this->scene_objectTextureLoc1);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->scene_objectTextureLoc1);
    
    // Skybox faces
    std::vector<std::string> faces = {
        "/Users/nwaters/code/go_stop/assets/skybox/right.jpg",
        "/Users/nwaters/code/go_stop/assets/skybox/left.jpg",
        "/Users/nwaters/code/go_stop/assets/skybox/top.jpg",
        "/Users/nwaters/code/go_stop/assets/skybox/bottom.jpg",
        "/Users/nwaters/code/go_stop/assets/skybox/back.jpg",
        "/Users/nwaters/code/go_stop/assets/skybox/front.jpg"
    };
    
    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++) {
        unsigned char * data = SOIL_load_image(faces[i].c_str(),
                                               &width,
                                               &height,
                                               &nrChannels,
                                               0);
        if (data) {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                         0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            SOIL_free_image_data(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            SOIL_free_image_data(data);
        }
    }
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

