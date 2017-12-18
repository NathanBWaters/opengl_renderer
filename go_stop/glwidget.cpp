#include "glwidget.h"
#include <QDebug>
#include <QOpenGLFunctions>

glWidget::glWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    timer_ = timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(reRender()));
    timer->start(1);
}

glWidget::~glWidget() {

}

void glWidget::reRender() {
    qDebug() << "called re-render";
//    processInput();
    update();
}


//void glWidget::processInput() {

//}

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

Scene * glWidget::getScene() {
    return scene_;
}

void glWidget::paintGL()
{
    // Draw the scene:
    glm::vec3 ambientLight = scene_->getAmbientLight(),
    glClearColor(ambientLight.r, ambientLight.g, ambientLight.b);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // don't forget to clear the stencil buffer!

    scene_->render();

    // calls itself to re-render
}
