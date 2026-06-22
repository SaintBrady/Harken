#include <cmath>
#include "vector3d.h"

Vector3D::Vector3D()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3D::Vector3D(const float x, const float y, const float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D& Vector3D::Normalized()
{
    float magnitude = sqrt((x*x) + (y*y) + (z*z));

    Vector3D* vec = new Vector3D(x/magnitude, y/magnitude, z/magnitude);
    return *vec;
}

void Vector3D::Normalize()
{
    *this = this->Normalized();
}

Vector3D& Vector3D::Add(const Vector3D& v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vector3D& Vector3D::Subtract(const Vector3D& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

Vector3D& Vector3D::Multiply(const Vector3D& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}

Vector3D& Vector3D::Multiply(const float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector3D& Vector3D::Divide(const Vector3D& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}

Vector3D& Vector3D::Divide(const float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

Vector3D& Vector3D::Cross(const Vector3D& v)
{
    float i, j, k;
    i = (y * v.z) - (v.y * z);
    j = (x * v.z) - (v.x * z);
    k = (x * v.y) - (v.x * y);

    Vector3D* vec = new Vector3D(i, -j, k);
    return *vec;
}

float Vector3D::Dot(const Vector3D& v)
{
    return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vector3D& operator+(Vector3D v1, const Vector3D& v2)
{
    return v1.Add(v2);
}

Vector3D& operator-(Vector3D v1, const Vector3D& v2)
{
    return v1.Subtract(v2);
}

Vector3D& operator*(Vector3D v1, const float scalar)
{
    return v1.Multiply(scalar);
}

Vector3D& operator*(Vector3D v1, const Vector3D& v2)
{
    return v1.Multiply(v2);
}

Vector3D& operator/(Vector3D v1, const float scalar)
{
    return v1.Divide(scalar);
}

Vector3D& operator/(Vector3D v1, const Vector3D& v2)
{
    return v1.Divide(v2);
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
    return this->Add(v);
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
    return this->Subtract(v);
}

Vector3D& Vector3D::operator*=(const Vector3D& v)
{
    return this->Multiply(v);
}

Vector3D& Vector3D::operator/=(const Vector3D& v)
{
    return this->Divide(v);
}

Vector3D& Vector3D::operator/=(const float scalar){
	x /= scalar;
	y /= scalar;
    z /= scalar;
	return *this;
}

void Vector3D::setPosition(const float x, const float y, const float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3D::setPosition(const Vector3D& v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& v)
{
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}