#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include "scene.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void settingBg();
    Scene *scene;
    QGraphicsPixmapItem *btn_back;
    int btn_small_w;
    int btn_small_h;




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
