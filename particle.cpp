// /*** Custom particle object inhereting from QGraphicsItem with included rudimentary physics
// *created by Julio Morgado
// ***/

// #include "particle.h"
// #include <QRandomGenerator>

// Particle::Particle(qreal X, qreal Y, qreal W, qreal H, qreal F, QString type)
//     : w(W), h(H), friction(F)
// {
//     res = 0.8;
//     a = new PVector(0, .4);
//     v = new PVector(QRandomGenerator::global()->bounded(4, 12), QRandomGenerator::global()->bounded(4, 12));
//     p = new PVector(X, Y);

//     pType = type;

//     setFlag(ItemIsMovable);
//     setFlag(ItemIsSelectable);
//     setFlag(ItemSendsScenePositionChanges);  // Necessary for detecting position
//     setCacheMode(DeviceCoordinateCache);
//     setAcceptedMouseButtons(Qt::LeftButton); // Ensure the item accepts left mouse button events

//     setPos(X, Y);
// }

// QRectF Particle::boundingRect() const {
//     qreal penWidth = 1; // Adjust if your outline/stroke width is different
//     return QRectF(-w / 2 - penWidth / 2, -h / 2 - penWidth / 2, w + penWidth, h + penWidth);
// }

// void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//     QPen pen(QColor(0, 0, 0));
//     QRadialGradient grad(QPointF(-3, -3), 0.6 * w);  // Centered at the origin

//     grad.setColorAt(0.0, QColor(255, 0, 0));
//     grad.setColorAt(1.0, QColor(0, 0, 0));

//     painter->setPen(pen);
//     painter->setBrush(grad);

//     if (pType == "Ball" || pType.isNull()) {
//         painter->drawEllipse(boundingRect());
//     } else if (pType == "Box") {
//         painter->drawRect(boundingRect());
//     } else {
//         qDebug() << "invalid pType";
//     }
// }

// QPainterPath Particle::shape() const
// {
//     QPainterPath path;
//     if (pType == "Ball" || pType.isNull()) {
//         path.addEllipse(boundingRect());
//     } else if (pType == "Box") {
//         path.addRect(boundingRect());
//     }
//     return path;
// }

// qreal Particle::radius()
// {
//     if (pType == "Ball" || pType.isNull()){
//         return w/2;
//     }
//     return 0;
// }

// PVector Particle::position()
// {
//     return *p;
// }

// void Particle::move(const PVector &d)
// {
//     p->setVector(p->x() + d.x(), p->y() + d.y());
// }

// void Particle::impulse(const PVector &d)
// {
//     if(scene()->mouseGrabberItem() != this){
//         v->setVector(d.x(), d.y());
//     }
//  }

// qreal Particle::speed()
// {
//     return v->mag();
// }

// void Particle::advance(int phase) {
//     if (!scene() || phase == 0) {
//         return;
//     }

//     updatePhysics();

//     prepareGeometryChange(); // Notify the scene about the geometry change
//     setPos(p->x(), p->y()); // Update the item's position
//     update();
// }

// void Particle::updatePhysics(){

//     if (scene()->mouseGrabberItem() == this) {
//         QPointF sceneMousePos = mapFromScene(lastMousePosition); // Convert to local coordinates
//         a->setVector((lastMousePosition.x() - p->x()), (lastMousePosition.y() - p->y()));
//         a->mult(.03);
//         v->mult(.95);
//     }

//     *v += *a;
//     *p += *v;

//     if (p->x() >= scene()->width() - w / 2) {
//         p->setX(scene()->width() - w / 2);
//         v->mult(-res, "x");
//     } else if (p->x() <= w / 2) {
//         p->setX(w / 2);
//         v->mult(-res, "x");
//     }

//     if (p->y() >= scene()->height() - h / 2) {
//         p->setY(scene()->height() - h / 2);
//         v->mult(-res, "y");
//         if (v->y() < std::numeric_limits<qreal>::epsilon()) {
//             v->mult(friction);
//         }
//     } else if (p->y() <= h / 2) {
//         p->setY(h / 2);
//         v->mult(-res, "y");
//     }
// }

// void Particle::mousePressEvent(QGraphicsSceneMouseEvent *event)
// {
//     lastMousePosition = event->scenePos(); // Use scene coordinates
// }

// void Particle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
// {
//     if (event->buttons() & Qt::LeftButton) {
//         lastMousePosition = event->scenePos(); // Use scene coordinates
//     }
// }

// void Particle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
//     a->setVector(0, .4);
// }

