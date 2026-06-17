#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

#include "item.h"
#include "player.h"

class Container
{
    public:
        int slots;
        Item** inventory;
        enum Type {
            CHEST = 5,
            BARREL = 3,
            CRATE = 2
        };

        Container(Type type);
        void genRandItems(Container &container);
        void open(Player& player, Container& container);
};

#endif