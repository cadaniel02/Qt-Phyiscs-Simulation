#include "collisions.h"
#include <QDebug>

Collisions::Collisions() {}

bool Collisions::intersectCircles(
    const PVector &center1, qreal radius1, const PVector &center2, qreal radius2,
    //return the normal vector and depth
    PVector &normal, qreal &depth)
{
    normal = PVector::Zero();
    depth = 0;

    qreal distance = (center2 - center1).length();
    qreal radii = radius1+radius2;

    if (distance >= radii){
        return false;
    }

    normal = PVector((center1 - center2).normalized());
    depth = radii - distance;

    qDebug() << "normal: " << normal << " depth: " << depth;

    return true;
}
