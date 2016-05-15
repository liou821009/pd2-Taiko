#include "scene.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;
//#include "mainwindow.h"
//#include "ui_mainwindow.h"


Scene::Scene(QObject *parent)
{
    screenMode = 0;

}


void Scene::Init()
{
    QImage bg;
    bg.load("D:\\C++_TaiKu\\Taiku\\Taiku_3.jpg");
    bg = bg.scaled(1000,560); // you can also change here
    setBackgroundBrush(bg);

    btn_start = new QGraphicsPixmapItem();
    QPixmap start;
    start.load("D:\\C++_TaiKu\\Taiku\\start.jpg");
    start = start.scaled(start.width()*1/2,start.height()*1/2,Qt::KeepAspectRatio);
    btn_start->setPixmap(start);
    btn_start->setPos(420,320);
    btn_w = (start.width()*3)/2 - 60;
    btn_h = (start.height()*3)/2 - 30;
    addItem(btn_start);
    btn_exit = new QGraphicsPixmapItem();
    QPixmap exit;
    exit.load("D:\\C++_TaiKu\\Taiku\\exit.jpg");
    exit = exit.scaled(start.width()*2,start.height()*2,Qt::KeepAspectRatio);
    btn_exit->setPixmap(exit);
    btn_exit->setPos(620,210);
    addItem(btn_exit);

}
void Scene::bgChange()
{
    btn_drum = new QGraphicsPixmapItem();
    QPixmap drum;
    drum.load("D:\\C++_TaiKu\\Taiku\\img\\mtaikoflash_red.png");
    drum = drum.scaled(drum.width()*2,drum.height()*2,Qt::KeepAspectRatio);
    btn_drum->setPixmap(drum);
    btn_drum->setPos(85,135);
    addItem(btn_drum);

    btn_back = new QGraphicsPixmapItem();
    QPixmap back;
    back.load("D:\\C++_TaiKu\\Taiku\\img\\back.png");
    back = back.scaled(back.width()*1/2,back.height()*1/2,Qt::KeepAspectRatio);
    btn_back->setPixmap(back);
    btn_back->setPos(900,20);
    addItem(btn_back);




    QImage bg;
    bg.load("D:\\C++_TaiKu\\Taiku\\img\\resultbg_clear.png");
    bg = bg.scaled(1005,600);
    this->setBackgroundBrush(bg);
    this->removeItem(btn_start);
    this->removeItem(btn_exit);

    time = new Gametime();
    time->setPos(50,20);
    this->addItem(time);

    QTimer * timer1 = new QTimer(time);
    connect(timer1,SIGNAL(timeout()),time,SLOT(move()));
    timer1->start(1000);




    score = new Score();
    score->setPos(500,20);
    this->addItem(score);
    key_count =0;


}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_w)
        {
           // Now x is in range , judge y
           if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h)
           {
               // x , y both in button area
              //cout<< btn_w<< endl;
               bgChange();
               gameInit();
               screenMode = 1;
            }
        }
        else if(event->scenePos().x() > btn_exit->pos().x() && event->scenePos().x() <= btn_exit->pos().x()+btn_w)
        {
            if(event->scenePos().y() > btn_exit->pos().y() && event->scenePos().y() <= btn_exit->pos().y()+btn_h)
            {
                exit(0);
                screenMode = 1;
            }
        }
    }
    else if(screenMode == 1)
    {
        if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_w)
        {
           // Now x is in range , judge y
           if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_h)
           {

               Init();
               removeItem(btn_drum);
               removeItem(time);
               removeItem(score);
               removeItem(btn_back);
               for(int i=0;i<50;i++)
               {
                   removeItem(ball[i]);
               }
               screenMode = 0;
            }
        }
    }

}

void Scene::gameInit()
{


    //key_count = key_count + check->get_checkover();
    for(int i=0;i<50;i++)
        {
            ball[i] = new Ball(btn_drum->pos().x(),btn_drum->pos().y());
            ball[i]->setPos(800+i*200,180);
            this->addItem(ball[i]);
        }



}

void Scene::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_J)
    {
        if(ball[key_count]->pos().y() > btn_drum->pos().y() && ball[key_count]->pos().y() <= btn_drum->pos().y()+btn_h)
        {
           // Now x is in range , judge y
           if(ball[key_count]->pos().x() > btn_drum->pos().x() && ball[key_count]->pos().x() <= btn_drum->pos().x()+btn_w && ball[key_count]->geti() == 0)
           {
                this->removeItem(ball[key_count]);
                score->increase();
                key_count++;
           }


        }
    }
    else if(event->key() == Qt::Key_K)
    {

        if(ball[key_count]->pos().y() > btn_drum->pos().y() && ball[key_count]->pos().y() <= btn_drum->pos().y()+btn_h)
        {
           // Now x is in range , judge y
           if(ball[key_count]->pos().x() > btn_drum->pos().x() && ball[key_count]->pos().x() <= btn_drum->pos().x()+btn_w&& ball[key_count]->geti() == 1)
           {
                this->removeItem(ball[key_count]);
                score->increase();
                key_count++;
           }

        }
    }
}

/*void Scene::scorebg()
{
    QImage scbg;
    scbg.load("D:\\C++_TaiKu\\Taiku\\img\\bglayer_gogo_p2.png");
    scbg = scbg.scaled(1005,600);
    this->setBackgroundBrush(scbg);
    this->removeItem(btn_drum);


}*/
