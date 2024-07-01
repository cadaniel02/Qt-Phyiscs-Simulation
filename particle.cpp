/*** Custom particle object inhereting from QGraphicsItem with included rudimentary physics
*created by Julio Morgado
***/

#include "particle.h"

Particle::Particle(qreal X, qreal Y, qreal W, qreal H, QString type)
{
    res = 0.8;
    w = W; h = H;
    a = new PVector(0, .1);
    v = new PVector(arc4random()%5 + 2, arc4random()%5 + 2);
    p = new PVector(X, Y);

    pType = type;

    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsScenePositionChanges);  // Necessary for detecting position changes
}

QRectF Particle::boundingRect() const
{
    return QRectF(p->x(), p->y(), w, h);
}


void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen (QColor(0,0,0));
    QRadialGradient grad(QPointF(p->x() + w/2, p->y() + h/2), 0.6 * w);
    grad.setColorAt(0.0, QColor(255,0,255));
    grad.setColorAt(1.0, QColor(0,0,0));

    painter->setPen(pen);
    painter->setBrush(grad);

    if (pType == "Ball" || pType == nullptr){
        painter->drawEllipse(boundingRect());
    }else if(pType == "Box"){
        painter->drawRect(boundingRect());
    }else {
        qDebug() << "invalid pType";
    }
}

void Particle::advance(int phase)
{
    if (!isDragging) {
        *v+=*a;
        *p+=*v;

        QPointF location(mapToScene(p->components()));

        if(location.x() >= scene()->width() - w){
            p->setX(scene()->width() - w);
            v->mult(-res,"x");
        } else if (location.x() <= 0){
            p->setX(0);
            v->mult(-res,"x");
        }

        if(location.y() >= scene()->height() - h){
            p->setY(scene()->height() - h);
            v->mult(-res,"y");
        } else if (location.y() <= 0){
            p->setY(0);
            v->mult(-res,"y");
        }
    }
    update();
}

void Particle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    offset = event->pos();
    isDragging = true;
}

void Particle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPointF newPos = mapToParent(event->pos() - offset);
        setPos(newPos);
    }
}

void Particle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isDragging = false;
}
