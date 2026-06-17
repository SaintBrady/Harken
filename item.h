#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "GameObject.h"

class Item : public GameObject
{
    public:
        int x;
        bool equippable;

        Item();
        Item(std::string name);

        void destroy();
        virtual void dummy() {};
};

bool operator==(const Item& item1, const Item& item2);

#endif