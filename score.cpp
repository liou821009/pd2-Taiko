#include "score.h"
#include <QFont>
#include <QGraphicsScene>

using namespace std;
Score::Score(QObject *parent)
{


    score = 0;
    setPlainText(QString("Score:      ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",40));



}

void Score::increase()
{
    score++;
    setPlainText(QString("Score:      ") + QString::number(score));

}

int Score::get_score()
{
    return score;
}

