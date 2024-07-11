    #include "pVector.h"


namespace MyPhysics {

    PVector::PVector(qreal X, qreal Y)
        : x(X), y() {}

    PVector PVector::Zero()
    {
        return PVector(0,0);
    }

    PVector PVector::operator-() const
    {
        return PVector(-x, -y);
    }

    PVector PVector::operator-(const PVector& v) const
    {
        return PVector(x - v.X(), y - v.Y());
    }

    PVector PVector::operator+(const PVector& v) const
    {
        return PVector(x + v.X(), y + v.Y());
    }

    PVector PVector::operator*(qreal scalar) const
    {
        return PVector(x * scalar, y * scalar);
    }

    PVector PVector::operator/(qreal scalar) const
    {
        return PVector(x / scalar, y / scalar);
    }

    qreal PVector::X() const
    {
        return this->x;
    }

    qreal PVector::Y() const
    {
        return this->y;
    }

}
