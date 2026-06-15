#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
    public:
        string name;
        int x;
        bool equippable;

        Item();
        Item(string name);

        void destroy();
};

bool operator==(const Item& item1, const Item& item2);

#endif