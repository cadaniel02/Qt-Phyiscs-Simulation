#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <pVector.h>

namespace MyPhysics{

class Collisions
{
public:
    Collisions();
    static bool intersectCircles(const PVector &center1, qreal radius1, const PVector &center2, qreal radius2, PVector &normal, qreal &depth);
};

}

#endif // COLLISIONS_H
