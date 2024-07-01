#ifndef PVECTOR_H
#define PVECTOR_H

#include <QVector2D>
#include <QtMath>

class PVector: public QVector2D
{
public:
    PVector(qreal x=0, qreal y=0);
    void setVector(qreal x, qreal y);

    PVector& operator+=(const PVector& v1);

    PVector& operator-=(const PVector& v1);

    void mult(qreal scalar, QString axis = nullptr);

    qreal mag();

    QPointF components();

};

#endif // PVECTOR_H
