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
    Particle(qreal X, qreal Y, qreal W, qreal H, qreal F, QString type = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const override;
    qreal radius();
    PVector position();
    void move(const PVector& d);
    void impulse(const PVector& d);
    qreal speed();
protected:
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    void updatePhysics();
    QPointF lastMousePosition;
    PVector *p, *v, *a;
    qreal w, h, m, res, friction;
    QString pType;
};


#endif // PARTICLE_H
