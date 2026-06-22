#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include "vector3d.h"
#include "mesh.h"

class Quaternion
{
    public:
        float w, x, y, z;

        Quaternion();
        Quaternion(const float w, const float x, const float y, const float z);
        Quaternion(const float w, const Vector3D& v);

        Quaternion& Add(const Quaternion& q2);
        Quaternion& Subtract(const Quaternion& q2);
        Quaternion& Multiply(const float scalar);
        Quaternion& Divide(const float scalar);

        friend Quaternion& operator*(Quaternion& q1, const Quaternion& q2);
        Quaternion& Rotate(Quaternion& q2, float speed);
        void Rotate(Mesh& g, Vector3D& axis, float theta);
        void Rotate(Vector3D& axis, const float theta);

        Quaternion& Conjugate();
        Quaternion& Normalized();
        void Normalize();
        friend std::ostream& operator<<(std::ostream& stream, const Quaternion& q1);
};

#endif