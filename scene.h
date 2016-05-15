#ifndef SCENE_H
#define SCENE_H




#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "ball.h"
#include <QList>
#include <QKeyEvent>
#include "gametime.h"
#include "score.h"



class Scene :public QGraphicsScene{


public:
    Scene(QObject *parent = 0);
    void Init();
    QGraphicsPixmapItem *btn_start;
    QGraphicsPixmapItem *btn_back;
    QGraphicsPixmapItem *btn_exit;
    QGraphicsPixmapItem *btn_drum;
    int screenMode;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int btn_w;
    int btn_h;

    void gameInit();
    QTimer *timer;
    QTimer * t;
    Ball * ball[50];
    void keyPressEvent(QKeyEvent * event);
    void bgChange();

    Gametime * time;
    Score * score;
    int key_count;

    void scorebg();
public slots:
    void geneNextBlock();


};

#endif // SCENE_H
