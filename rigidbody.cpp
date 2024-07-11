#include "rigidbody.h"
#include <QString>
#include <QtMath>

namespace MyPhysics {

    RigidBody::RigidBody(PVector position, qreal density, qreal mass, qreal restitution, qreal area, bool isStatic, qreal radius, qreal width, qreal height, ShapeType shape)
        : position(position), Density(density), Mass(mass), Restitution(restitution), Area(area), isStatic(isStatic), Radius(radius), Width(width), Height(height), Shape(shape) {
}
    bool RigidBody::CreateCircleBody(qreal radius, PVector position, qreal density, bool isStatic, qreal restitution, RigidBody*& body, QString& error)
    {
        body = nullptr;
        error = "";

        if (density <= 0 || radius <= 0) {
            error = "Invalid density or radius.";
            return false;
        }

        qreal area = M_PI * radius * radius;
        qreal mass = area / density;

        body = new RigidBody(position, density, mass, restitution, area, isStatic, radius, 0, 0, ShapeType::Circle);
        return true;

    }
} //namespace MyPhysics
