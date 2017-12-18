#include <QtDebug>
#include <QKeyEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"



MainWindow::MainWindow(QWidget *parent, Scene *scene) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->glWidgetWindow->setScene(scene);

    ui->pushButton->setText("mkmkmkmk");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    qInfo() << "Hit key press";

    if (event->key() == Qt::Key_U) {
        qInfo() << "Hit U";
    }

    float deltaTime = 0.1f;

    if (event->key() == Qt::Key_E) {
        ui->glWidgetWindow->getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_FORWARD, deltaTime);
    }
    if (event->key() == Qt::Key_Q) {
        ui->glWidgetWindow->getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_BACKWARD, deltaTime);
    }
    if (event->key() == Qt::Key_A) {
        ui->glWidgetWindow->getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_LEFT, deltaTime);
    }
    if (event->key() == Qt::Key_D) {
        ui->glWidgetWindow->getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_RIGHT, deltaTime);
    }
    if (event->key() == Qt::Key_S) {
        ui->glWidgetWindow->getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_DOWN, deltaTime);
    }
    if (event->key() == Qt::Key_W) {
        ui->glWidgetWindow->getScene()->getCamera()->ProcessKeyboard(CAMERA_MOVE_UP, deltaTime);
    }
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "You hit a button!";
}
