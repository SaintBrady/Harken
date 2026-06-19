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
    Vector3D* v1 = new Vector3D(q1.x, q1.y, q1.z);
    Vector3D* v2 = new Vector3D(q2.x, q2.y, q2.z);

    Quaternion* q = new Quaternion(((q1.w * q2.w) - v1->Dot(*v2)), ((*v2 * q1.w) + (*v1 * q2.w) + (v1->Cross(*v2))));

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
Quaternion& Quaternion::Rotate(Quaternion& q2)
{
    return (q2 * (*this));
}