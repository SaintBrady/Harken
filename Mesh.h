#ifndef MESH_H
#define MESH_H

#include <vector>
#include "vector3d.h"

class Mesh
{
    public:
        std::vector<Vector3D*> points;
};

#endif