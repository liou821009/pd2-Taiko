#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QDesktopWidget wid;
    int screenW = 1019; // change to 400 to fit the screen
    int screenH = 680; // change to 700 to fit the screen
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);



    w.setWindowTitle("TaiKu");
    w.setWindowIcon(QIcon("D:\\C++_TaiKu\\Taiku\\Taiku.jpg"));

    w.show();

    return a.exec();
}
