#include "glwidget.h"
#include <QDebug>
#include <QOpenGLFunctions>

glWidget::glWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{

}

glWidget::~glWidget() {

}

/**
 * @brief glWidget::setScene
 * @param scene - the scene you want to set the window to
 */
void glWidget::setScene(Scene *scene) {
    scene_ = scene;
}

void glWidget::initializeGL()
{
    qDebug() << "Inside debug";
    scene_->initialize();
}


void glWidget::paintGL()
{
    qDebug() << "Called paintGL with scene: " << scene_;
    // Draw the scene:
    glm::vec3 ambientLight = scene_->getAmbientLight(),
    glClearColor(ambientLight.r, ambientLight.g, ambientLight.b);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // don't forget to clear the stencil buffer!

    scene_->render();
}
