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
#include "skybox/skybox.hpp"
#include "framebuffer/framebuffer.hpp"
#include "triangle/triangle.hpp"
#include "point_light/point_light.hpp"
#include "scene/Scene.hpp"

// Window settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

// Camera settings
Camera camera(glm::vec3(0.0f, 0.0f, 9.0f));
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;
//extern bool useMouseControls;

// Light Settings
glm::vec3 ambientLight = glm::vec3(0.1f, 0.1f, 0.1f);

// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
