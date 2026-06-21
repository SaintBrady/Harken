#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3d.h"
#include "quaternion.h"

class Transform
{
    public:
        Vector3D position;
        Vector3D scale;
        Quaternion rotation;

        Transform();
};

#endif