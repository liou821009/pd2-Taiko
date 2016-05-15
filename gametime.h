#ifndef GAMETIME_H
#define GAMETIME_H


#include <QGraphicsTextItem>

class Gametime:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Gametime(QObject *parent = 0);
    int get_gametime();
public slots:
    void move();
    //void checktime();

private:
    int gametime;
};



#endif // GAMETIME_H
