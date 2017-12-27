#include "glwidget.h"
#include "model/model.hpp"

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;

glWidget::glWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    timer_ = timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(reRender()));
    timer->start(FPS);

    setupInputMap();
}

void glWidget::setupInputMap() {
    manager_ = new gainput::InputManager;
    manager_->SetDisplaySize(SCREEN_WIDTH, SCREEN_HEIGHT);
    mouseId_ = manager_->CreateDevice<gainput::InputDeviceMouse>();
    keyboardId_ = manager_->CreateDevice<gainput::InputDeviceKeyboard>();
    padId_ = manager_->CreateDevice<gainput::InputDevicePad>();

    map_ = new gainput::InputMap(*manager_);
    map_->MapBool(KeyUp, keyboardId_, gainput::KeyW);
    map_->MapBool(KeyLeft, keyboardId_, gainput::KeyA);
    map_->MapBool(KeyDown, keyboardId_, gainput::KeyS);
    map_->MapBool(KeyRight, keyboardId_, gainput::KeyD);
    map_->MapBool(KeyForward, keyboardId_, gainput::KeyE);
    map_->MapBool(KeyBackward, keyboardId_, gainput::KeyQ);
    map_->MapBool(KeyOption, keyboardId_, gainput::KeyAltL);

    map_->MapFloat(MouseX, mouseId_, gainput::MouseAxisX);
    map_->MapFloat(MouseY, mouseId_, gainput::MouseAxisY);
}

glWidget::~glWidget() {

}

void glWidget::reRender() {
    processInput();
    update();
}


void glWidget::processInput() {
    manager_->Update();

    // Get vector of mouse delta from previous frame to determine camera lookAt
    // direction.
    if (map_->GetBool(KeyOption)) {
        if (map_->GetFloatDelta(MouseX) != 0.0f || map_->GetFloatDelta(MouseY) != 0.0f)
        {
            std::cout << "Got a difference!" << std::endl;
            getScene()->getCamera()->ProcessMouseMovement(map_->GetFloatDelta(MouseX),
                                                          map_->GetFloatDelta(MouseY));
        }
    }

    // Move the camera Forward
    if (map_->GetBool(KeyForward)) {
        std::cout << "Foward" << std::endl;
        getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_FORWARD, UPDATE_AMOUNT);
    }
    // Move the camera Backward
    if (map_->GetBool(KeyBackward)) {
        std::cout << "Backward" << std::endl;
        getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_BACKWARD, UPDATE_AMOUNT);
    }
    // Move the camera Left
    if (map_->GetBool(KeyLeft)) {
        std::cout << "Left" << std::endl;
        getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_LEFT, UPDATE_AMOUNT);
    }
    // Move the camera Right
    if (map_->GetBool(KeyRight)) {
        getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_RIGHT, UPDATE_AMOUNT);
    }
    // Move the camera Down
    if (map_->GetBool(KeyDown)) {
        getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_DOWN, UPDATE_AMOUNT);
    }
    // Move the camera Up
    if (map_->GetBool(KeyUp)) {
        getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_UP, UPDATE_AMOUNT);
    }
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

Scene * glWidget::getScene() {
    return scene_;
}

void glWidget::paintGL()
{
    // Draw the scene:
    glm::vec3 ambientLight = scene_->getAmbientLight();
    glClearColor(ambientLight.r, ambientLight.g, ambientLight.b, 1.0f);
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // don't forget to clear the stencil buffer!
    scene_->render();

    // calls itself to re-render
}
