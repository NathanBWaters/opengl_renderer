#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include <QtDebug>


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

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "You hit a button!";
}
