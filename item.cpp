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

bool Item::operator==(const Item& item)
{
    return this->name == item.name;
}