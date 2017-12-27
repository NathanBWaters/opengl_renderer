#include "mainwindow.h"
#include <QApplication>
#include <QtGui>

#include <assimp/Importer.hpp>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "Shader.hpp"
#include "Camera.hpp"

#include "scene_object/scene_object.hpp"
#include "model/model.hpp"
#include "mesh/mesh.hpp"
#include "cube/cube.hpp"
//#include "skybox/skybox.hpp"
#include "framebuffer/framebuffer.hpp"
#include "triangle/triangle.hpp"
#include "point_light/point_light.hpp"
#include "scene/Scene.hpp"

// Window settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

// Camera settings
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;
//extern bool useMouseControls;

// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set GLSL format to version 330.
    QSurfaceFormat glFormat;
    glFormat.setVersion(3, 3);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(glFormat);

    // create initial scene
    Camera camera(glm::vec3(0.0f, 0.0f, 9.0f));

    Scene scene(&camera, glm::vec3(0.5f, 0.1f, 0.1f));

    Cube scene_object(&scene,
                  glm::vec3(2.0f, 0.0f, 2.0f),
                  glm::vec3(0.0f, 0.0f, 0.0f),
                  glm::vec3(1.0f, 1.0f, 1.0f));

    Cube scene_object2(&scene,
               glm::vec3(0.0f, 3.0f, -1.0f),
               glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3(1.0f, 1.0f, 1.0f));

    Cube scene_object3(&scene,
               glm::vec3(-3.0f, 2.0f, -7.0f),
               glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3(1.0f, 1.0f, 1.0f));

    // blue light
    PointLight pointLight1(&scene,
                           glm::vec3(0.4f, 0.6f, 2.2f),
                           glm::vec3(-1.0f, 1.3f, 5.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));

    // orange light
    PointLight pointLight2(&scene,
                           glm::vec3(1.0f, 0.5f, 0.2f),
                           glm::vec3(2.0f, 2.5f, -1.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));

    // green light
    PointLight pointLight3(&scene,
                           glm::vec3(0.5f, 2.0f, 0.2f),
                           glm::vec3(0.0f, -2.5f, -2.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.2f, 0.2f, 0.2f));

    Model nanoSuit(&scene,
                   "/Users/nwaters/code/go_stop/assets/nanosuit/nanosuit.obj",
                   glm::vec3(-1.0f, 0.0f, 2.0f),
                   glm::vec3(0.0f, 0.0f, 0.0f),
                   glm::vec3(0.2f, 0.2f, 0.2f));

    // create main window
    MainWindow w(0, &scene);
    w.resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    w.show();

    return app.exec();
}
