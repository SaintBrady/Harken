#include <cmath>
#include "quaternion.h"

Quaternion::Quaternion()
{
    w = 1.0f;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Quaternion::Quaternion(const float w, const float x, const float y, const float z)
{
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

Quaternion::Quaternion(const float w, const Vector3D& v)
{
    this->w = w;
    x = v.x;
    y = v.y;
    z = v.z;
}

Quaternion& Quaternion::Add(const Quaternion& q2)
{
    w += q2.w;
    x += q2.x;
    y += q2.y;
    z += q2.z;

    return *this;
}

Quaternion& Quaternion::Subtract(const Quaternion& q2)
{
    w -= q2.w;
    x -= q2.x;
    y -= q2.y;
    z -= q2.z;

    return *this;
}

Quaternion& Quaternion::Multiply(const float scalar)
{
    w *= scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Quaternion& Quaternion::Divide(const float scalar)
{
    w /= scalar;
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

Quaternion& operator*(Quaternion& q1, const Quaternion& q2)
{
    Quaternion* q = new Quaternion( 
        ((q1.w*q2.w) - (q1.x*q2.x) - (q1.y*q2.y) - (q1.z*q2.z)), 
        ((q1.w*q2.x) + (q1.x*q2.w) + (q1.y*q2.z) - (q1.z*q2.y)), 
        ((q1.w*q2.y) - (q1.x*q2.z) + (q1.y*q2.w) + (q1.z*q2.x)), 
        ((q1.w*q2.z) + (q1.x*q2.y) - (q1.y*q2.x) + (q1.z*q2.w)) );

    return *q;
}

Quaternion& Quaternion::Conjugate()
{
    Quaternion *q1 = new Quaternion(w, -x, -y, -z);
    return *q1;
}

Quaternion& Quaternion::Normalized()
{
    float norm = sqrt((w*w) + (x*x) + (y*y) + (z*z));
    Quaternion *q2 = new Quaternion(w, x, y, z);

    return q2->Divide(norm);
}

void Quaternion::Normalize()
{
    *this = this->Normalized();
}

std::ostream& operator<<(std::ostream& stream, const Quaternion& q1)
{
    stream << q1.w << " + " << q1.x << "i + " << q1.y << "j + " << q1.z << "k";
    return stream;
}

// Global rotates around other Quaternion
Quaternion& Quaternion::Rotate(Quaternion& q2, float speed)
{
    return (q2 * (*this) *(this->Conjugate())).Multiply(speed);
}

void Quaternion::Rotate(Mesh& g, Vector3D& axis, float theta)
{
    axis.Normalize();
    float sine = sin(theta/2);
    w = cos(theta/2);
    x = axis.x * sine;
    y = axis.y * sine;
    z = axis.z * sine;

    for(Vector3D *point : g.points)
    {
        Quaternion p(0.0, *point);
        Quaternion q2 = this->Conjugate();
        Quaternion qPrime = (*this) * p * q2;

        point->x = qPrime.x;
        point->y = qPrime.y;
        point->z = qPrime.z;
    }
}

void Quaternion::Rotate(Vector3D& axis, const float theta)
{
    axis.Normalize();
    float sine = sin(theta / 2);
    w = cos(theta / 2);
    x = axis.x * sine;
    y = axis.y * sine;
    z = axis.z * sine;
}