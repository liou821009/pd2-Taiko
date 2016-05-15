#include "ball.h"
#include<iostream>
#include <ctime>
#include <cstdlib>
#include <QTimer>

using namespace std;
Ball::Ball(int drum_x,int drum_y)
{
    seti();
    y = 0;
    x = 1;
    drum = 300;
    dx = drum_x;
    dy = drum_y;
    if(i == 0)
    {
        this->setPixmap(QPixmap("D:\\C++_TaiKu\\Taiku\\img\\A.png"));
        this->setScale(4);
    }
    else
    {
        this->setPixmap(QPixmap("D:\\C++_TaiKu\\Taiku\\img\\B.png"));
        this->setScale(4);
    }



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(5);

}
void Ball::move()
{

    this->setPos(this->pos().x()-x, this->pos().y());
    checkboundary();
}

void Ball::checkboundary()
{
    now_x = this->pos().x();
    now_y = this->pos().y();

    if(now_x < dx - 100)
    {
        delete(this);
        check++;
    }

}
int Ball::get_check()
{
    return check;
}


int Ball::geti()
{
    return i;
}
void Ball::seti()
{
    i = rand()%2;
}


int Ball::check = 0;

