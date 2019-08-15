#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QOpenGLFunctions>
#include <gainput/gainput.h>

#include "scene/Scene.hpp"
#include "mesh/mesh.hpp"
#include "cube/cube.hpp"
#include "point_light/point_light.hpp"

class glWidget : public QOpenGLWidget
{

private:
    Q_OBJECT
    Scene *scene_;
    QTimer *timer_;

    gainput::InputManager* manager_;
    gainput::InputMap* map_;
    gainput::DeviceId mouseId_;
    gainput::DeviceId keyboardId_;
    gainput::DeviceId padId_;

    // Define your user buttons
    enum KeyboardKeys
    {
        KeyUp,
        KeyLeft,
        KeyDown,
        KeyRight,
        KeyForward,
        KeyBackward,
        KeyOption,
        MouseX,
    	MouseY,
    };

    float FPS = 16.666666666f;
    float UPDATE_AMOUNT = FPS / 1000.0F;

private slots:
    void reRender();

public:
    glWidget(QWidget *parent = nullptr);
    ~glWidget();

    void initializeGL();

    void setupInputMap();

    void setScene(Scene *scene);

    void processInput();

    Scene * getScene();

    void paintGL();


};

#endif // GLWIDGET_H
