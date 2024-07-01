    #include "pVector.h"


    PVector::PVector(qreal x, qreal y)
    {
        setVector(x,y);
    }

    void PVector::setVector(qreal x, qreal y)
    {
        setX(x);
        setY(y);
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

    PVector &PVector::operator-=(const PVector &v1)
    {
        setX(x() - v1.x());
        setY(y() + v1.y());
        return *this;
    }

    void PVector::mult(qreal scalar, QString axis)
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
