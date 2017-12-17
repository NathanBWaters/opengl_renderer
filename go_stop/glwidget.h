#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "scene/Scene.hpp"
#include "mesh/mesh.hpp"
#include "cube/cube.hpp"
#include "point_light/point_light.hpp"

class glWidget : public QOpenGLWidget
{
private:
    Scene *scene_;

public:
    glWidget(QWidget *parent = nullptr);
    ~glWidget();

    void initializeGL();

    void setScene(Scene *scene);

    void paintGL();
};

#endif // GLWIDGET_H
