#include "gametime.h"
#include <QFont>
#include <QTimer>
#include <QGraphicsScene>
#include <iostream>
#include <stdlib.h>
using namespace std;
Gametime::Gametime(QObject *parent)
{
    gametime = 30;
    setPlainText(QString("Time:      ") + QString::number(gametime)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",40));
}

void Gametime::move()
{

    if(gametime != 0)
    {
        gametime--;
        setPlainText(QString("Time:      ") + QString::number(gametime));
    }
}

int Gametime::get_gametime()
{
    return gametime;
}

/*void Gametime::checktime()
{
    if(get_gametime() == 0)
    {
        cout << "fdsfsaf" << endl;
    }
}*/
