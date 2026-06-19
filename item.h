#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
    public:
        int x;
        bool equippable;

        Item();
        Item(std::string name);

        bool operator==(const Item& item);

        void destroy();
};

#endif