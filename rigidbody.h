#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <QGraphicsItem>
#include <QString>
#include <pVector.h>

namespace MyPhysics{

enum ShapeType
{
    Circle = 0,
    Box = 1
};

class RigidBody final: public QGraphicsItem
{
private:
    // void updatePhysics();
    // QPointF lastMousePosition;
    PVector position, linear_velocity;
    qreal angle, rotational_velocity;
public:
    RigidBody(PVector position, qreal density, qreal mass, qreal restitution, qreal area, bool isStatic, qreal radius, qreal width, qreal height, ShapeType shape);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    void move(const PVector& d);
    void impulse(const PVector& d);

    const qreal Density;
    const qreal Mass;
    const qreal Restitution;
    const qreal Area;

    const bool isStatic;

    const qreal Radius;
    const qreal Width;
    const qreal Height;

    const ShapeType Shape;

    static bool CreateCircleBody
        (qreal radius, PVector position, qreal density, bool isStatic, qreal restitution,
        RigidBody*& body, QString& error);

protected:
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

}
#endif // RIGIDBODY_H
