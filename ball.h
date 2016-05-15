#ifndef BALL_H
#define BALL_H


#include <QGraphicsPixmapItem>
#include <iostream>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>


using namespace std;

class Ball : public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Ball(int drum_x,int drum_y);

    void seti();
    int y,now_x,now_y,dx,dy;
    float x;
    int drum;
    int geti();
    void checkboundary();
    int get_check();
static int check;

public slots:
    void move();
private:
    int i;
    //int check;

};





#endif // BALL_H
