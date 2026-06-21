#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "transform.h"
#include "vector3d.h"
#include "mesh.h"

class GameObject
{
    public:
        std::string name;

        Transform transform;
        Mesh mesh;
};

#endif