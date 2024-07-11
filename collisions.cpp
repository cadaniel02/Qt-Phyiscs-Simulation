#include "collisions.h"
#include <QDebug>
#include "pmath.h"

namespace MyPhysics{

Collisions::Collisions() {}

bool Collisions::intersectCircles(
    const PVector &center1, qreal radius1, const PVector &center2, qreal radius2,
    //return the normal vector and depth
    PVector &normal, qreal &depth)
{
    depth = 0;

    qreal distance = PMath::distance(center1, center2);
    qreal radii = radius1+radius2;

    if (distance >= radii){
        return false;
    }

    normal = PMath::normalize(center1 - center2);
    depth = radii - distance;
    return true;
}

}
