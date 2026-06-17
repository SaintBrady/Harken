#include <string>

#include "item.h"

bool equippable;

Item::Item(){}

Item::Item(std::string name)
{
    this->name = name;
    equippable = false;
}

void Item::destroy()
{

}

bool operator==(const Item& item1, const Item& item2)
{
    return item1.name == item2.name;
}