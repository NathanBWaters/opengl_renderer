//
//  model.hpp
//  go_stop
//
//  Created by Nathan Waters on 12/2/17.
//  Copyright © 2017 Nathan Waters. All rights reserved.
//


#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../scene_object/scene_object.hpp"
#include "../mesh/mesh.hpp"
#include "Shader.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Model : public SceneObject
{
public:
    /*  Model Data */
    vector<Texture> textures_loaded;    // stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    vector<Mesh> meshes;
    string directory;
    bool gammaCorrection;
    
    /*  Functions   */
    // constructor, expects a filepath to a 3D model.
    Model(Scene* scene,
          string const &path,
          glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
          glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f),
          glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
    
    // draws the model, and thus all its meshes
    void Draw(Shader shader);
    
    void setDefaultShader();
    
private:
    /*  Functions   */
    // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
    void loadModel(string const &path);
    
    // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
    void processNode(aiNode *node, const aiScene *scene);
    
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
    
    unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);
};

#endif

