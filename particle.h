#ifndef PARTICLE_H
#define PARTICLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <QObject>
#include <QDebug>
#include "pVector.h"


class Particle: public QGraphicsItem
{
public:
    Particle(qreal X, qreal Y, qreal W, qreal H, QString type = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPointF offset;
    PVector *p, *v, *a;
    qreal w, h, m, res;
    QString pType;
    bool isDragging;
};


#endif // PARTICLE_H
