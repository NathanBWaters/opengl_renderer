#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QObject>

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

private slots:
    void reRender();

public:
    glWidget(QWidget *parent = nullptr);
    ~glWidget();

    void initializeGL();

    void setScene(Scene *scene);

    Scene * getScene();

    void paintGL();


};

#endif // GLWIDGET_H
