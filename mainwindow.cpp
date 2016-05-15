#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1019,620);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,10,995,550); // change the value to fit
    scene->Init();


    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}




