#ifndef PVECTOR_H
#define PVECTOR_H

#include <QVector2D>
#include <QtMath>

class PVector: public QVector2D
{
public:
    PVector(qreal x=0, qreal y=0);
    PVector(QVector2D v);

    void setVector(qreal x, qreal y);
    void setVector(QPointF p);

    static PVector Zero();

    PVector& operator+=(const PVector& v1);

    PVector& operator+=(const QPointF& p);

    PVector& operator-=(const PVector& v1);

    PVector& operator-=(const QPointF& p);

    PVector operator-() const;

    PVector operator*(qreal scalar) const;

    PVector mult(qreal scalar, QString axis = nullptr);

    qreal mag();

    QPointF components();

};

#endif // PVECTOR_H
