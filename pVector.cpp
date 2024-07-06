    #include "pVector.h"


    PVector::PVector(qreal x, qreal y)
    {
        setVector(x,y);
    }

    PVector::PVector(QVector2D v)
    {
        setVector(v.x(), v.y());
    }

    void PVector::setVector(qreal x, qreal y)
    {
        setX(x);
        setY(y);
    }

    void PVector::setVector(QPointF p)
    {
        setX(p.x());
        setY(p.y());
    }

    PVector PVector::Zero()
    {
        return PVector(0,0);
    }

    qreal PVector::mag()
    {
        return qSqrt( qPow(x() , 2) + qPow(y(), 2) );
    }

    QPointF PVector::components()
    {
        return QPointF(x(), y());
    }

    PVector &PVector::operator+=(const PVector &v1)
    {
        setX(x() + v1.x());
        setY(y() + v1.y());
        return *this;
    }

    PVector &PVector::operator+=(const QPointF &p)
    {
        setX(x() + p.x());
        setY(y() + p.y());
        return *this;
    }

    PVector &PVector::operator-=(const PVector &v1)
    {
        setX(x() - v1.x());
        setY(y() + v1.y());
        return *this;
    }

    PVector &PVector::operator-=(const QPointF &p)
    {
        setX(x() - p.x());
        setY(y() + p.y());
        return *this;
    }

    PVector PVector::operator-() const
    {
        return PVector(-x(), -y());
    }

    PVector PVector::operator*(qreal scalar) const
    {
        return PVector(x() * scalar, y() * scalar);
    }

    PVector PVector::mult(qreal scalar, QString axis)
    {
        if (axis.compare("x", Qt::CaseInsensitive) == 0){
            setX(x() * scalar);
        }
        else if (axis.compare("y", Qt::CaseInsensitive) == 0){
            setY(y() * scalar);
        }
        else{
            setX(x() * scalar);
            setY(y() * scalar);
        }
    }
