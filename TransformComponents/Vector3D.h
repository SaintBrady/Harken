#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D
{
    public:
        float x, y, z;

        Vector3D();
        Vector3D(const float x, const float y, const float z);

        Vector3D& Add(const Vector3D& v);
        Vector3D& Subtract(const Vector3D& v);
        Vector3D& Multiply(const float scalar);
        Vector3D& Multiply(const Vector3D& v);
        Vector3D& Divide(const float scalar);
        Vector3D& Divide(const Vector3D& v);
        Vector3D& Cross(const Vector3D& v);
        float Dot(const Vector3D& v);

        friend Vector3D& operator+(Vector3D v1, const Vector3D& v2);
        friend Vector3D& operator-(Vector3D v1, const Vector3D& v2);
        friend Vector3D& operator*(Vector3D v1, const float scalar);
        friend Vector3D& operator*(Vector3D v1, const Vector3D& v2);
        friend Vector3D& operator/(Vector3D v1, const float scalar);
        friend Vector3D& operator/(Vector3D v1, const Vector3D& v2);
        friend std::ostream& operator<<(std::ostream& stream, const Vector3D& v);

        Vector3D& operator+=(const Vector3D& v);
        Vector3D& operator-=(const Vector3D& v);
        Vector3D& operator*=(const Vector3D& v);
        Vector3D& operator/=(const Vector3D& v);
        Vector3D& operator/=(float scalar);

        Vector3D& Normalized();

        void setPosition(const float x, const float y, const float z);
        void setPosition(const Vector3D& v);
};

#endif