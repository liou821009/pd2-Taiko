#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QObject *parent = 0);

    int get_score();
public slots:
    void increase();

private:
    int score;
};





#endif // SCORE_H
