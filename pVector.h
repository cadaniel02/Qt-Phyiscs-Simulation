#ifndef PVECTOR_H
#define PVECTOR_H

#include <QObject>
#include <QVector2D>
#include <QtMath>
#include <QString>

namespace MyPhysics{

class PVector {
public:

    static PVector Zero();

    PVector(qreal x = 0, qreal y = 0);

    PVector operator-() const;

    PVector operator-(const PVector& v) const;

    PVector operator+(const PVector& v) const;

    PVector operator*(qreal scalar) const;

    PVector operator/(qreal scalar) const;

    bool Equals(const PVector& other);

    qreal X() const;

    qreal Y() const;

private:
    qreal x, y;

};

}
#endif // PVECTOR_H
