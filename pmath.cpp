#include "pmath.h"
#include <QtMath>

namespace MyPhysics {

qreal PMath::length(const PVector &v)
{
    return qSqrt(v.X()*v.X() + v.Y()*v.Y());
}

qreal PMath::distance(const PVector &v1, const PVector &v2)
{
    return qSqrt((v1.X()-v2.X()) * (v1.X()-v2.X()) + (v1.Y()-v2.Y()) * (v1.Y()-v2.Y()));
}

PVector PMath::normalize(const PVector &v)
{
    qreal l = length(v);
    return PVector(v.X()/l, v.Y()/l);
}

qreal PMath::dot(const PVector &v1, const PVector &v2)
{
    return v1.X() * v2.X() + v1.Y() * v2.Y();
}

}
