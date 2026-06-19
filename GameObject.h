#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "transform.h"

class GameObject
{
    public:
        std::string name;

        Transform transform;
};

#endif