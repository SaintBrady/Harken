#include <string>

#include "item.h"

using namespace std;

string name = "";
int x = -1;
bool equippable = false;

Item::Item(){}

Item::Item(string name)
{
    this->name = name;
}

void Item::destroy()
{

}

bool operator==(const Item& item1, const Item& item2)
{
    return item1.name == item2.name;
}