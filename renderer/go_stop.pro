#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T16:58:55
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = go_stop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cube/cube.cpp \
    framebuffer/framebuffer.cpp \
    mesh/mesh.cpp \
    model/model.cpp \
    point_light/point_light.cpp \
    scene/Scene.cpp \
    scene_object/scene_object.cpp \
    skybox/skybox.cpp \
    triangle/triangle.cpp \
    particle_system/particle_system.cpp \
    glwidget.cpp

HEADERS += \
        mainwindow.h \
        Shader.hpp \
        Camera.hpp \
    cube/cube.hpp \
    framebuffer/framebuffer.hpp \
    mesh/mesh.hpp \
    model/model.hpp \
    point_light/point_light.hpp \
    scene/Scene.hpp \
    scene_object/scene_object.hpp \
    skybox/skybox.hpp \
    triangle/triangle.hpp \
    particle_system/particle_system.hpp \
    particle/particle.hpp \
    glwidget.h

FORMS += \
        mainwindow.ui

unix: LIBS += -L$$PWD/../lib/ -lassimp.4.0.1

INCLUDEPATH += $$PWD/../lib/assimp
DEPENDPATH += $$PWD/../lib/assimp

unix: LIBS += -L$$PWD/../lib/ -lassimp.4.0.1

INCLUDEPATH += $$PWD/../../glm
DEPENDPATH += $$PWD/../../glm

DISTFILES += \
    border/border.frag \
    framebuffer/framebuffer.frag \
    point_light/point_light.frag \
    scene_object/scene_object.frag \
    skybox/skybox.frag \
    framebuffer/framebuffer.vert \
    model/model.vert \
    point_light/point_light.vert \
    scene_object/scene_object.vert \
    particle_system/particle_system.vert \
    particle_system/particle_system.frag \
    skybox/skybox.vert

unix: LIBS += -L$$PWD/../lib/ -lSOIL

INCLUDEPATH += $$PWD/../lib/SOIL
DEPENDPATH += $$PWD/../lib/SOIL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lassimp.4.0.1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lassimp.4.0.1
else:unix: LIBS += -L$$PWD/../lib/ -lassimp.4.0.1

INCLUDEPATH += $$PWD/../lib/assimp
DEPENDPATH += $$PWD/../lib/assimp

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/gainput-1.0.0/lib/release/ -lgainput.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/gainput-1.0.0/lib/debug/ -lgainput.1.0.0
else:unix: LIBS += -L$$PWD/../lib/gainput-1.0.0/lib/ -lgainput.1.0.0

INCLUDEPATH += $$PWD/../lib/gainput
DEPENDPATH += $$PWD/../lib/gainput
