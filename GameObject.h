#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "vector2d.h"

class GameObject
{
    public:
        std::string name;

        Vector2D position;
};

#endif