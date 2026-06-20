#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "transform.h"
#include "mesh.h"

class GameObject
{
    public:
        std::string name;

        Transform transform;
        Mesh mesh;
};

#endif