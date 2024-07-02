#include "customscene.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent) {}

void CustomScene::drawBackground(QPainter *painter, const QRectF &rect) {
    QPen pen(QColor(0, 0, 0));
    painter->setPen(pen);

    QPainterPath path;
    for (QGraphicsItem *item : items()) {
        Particle *particle = dynamic_cast<Particle*>(item);
        if (particle) {
            if (particle->pType == "Ball" || particle->pType.isNull()) {
                path.addEllipse(particle->boundingRect());
            } else if (particle->pType == "Box") {
                path.addRect(particle->boundingRect());
            } else {
                qDebug() << "invalid pType";
            }
        }
    }

    QRadialGradient grad(QPointF(sceneRect().width() / 2, sceneRect().height() / 2), sceneRect().width() / 2);
    grad.setColorAt(0.0, QColor(255, 0, 255));
    grad.setColorAt(1.0, QColor(0, 0, 0));

    painter->setBrush(grad);
    painter->drawPath(path);
}
