#ifndef PMATH_H
#define PMATH_H

#include "pVector.h"

namespace MyPhysics {

class PMath
{
public:
    static qreal length(const PVector &v);
    static qreal distance(const PVector &v1, const PVector &v2);
    static PVector normalize(const PVector &v);
    static qreal dot(const PVector &v1, const PVector &v2);
};

}

#endif // PMATH_H
