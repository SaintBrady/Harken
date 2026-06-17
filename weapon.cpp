#include <string>
#include <map>
#include <iostream>

#include "item.h"
#include "weapon.h"

using namespace std;

Weapon::Weapon(string name)
{
    this->name = name;
    equippable = true;
    damage = weaponsTable[weaponsAlias[name]][1];
    critRating = weaponsTable[weaponsAlias[name]][2] / 100.0;
}

map<string, int> Weapon::weaponsAlias =
{
    {"Unarmed", 0},
    {"Gore Dagger", 1},
    {"Radiant Mace", 2},
    {"Rusty Knife", 3}
};

// ID, Damage, Crit Rating
int Weapon::weaponsTable[4][3] = {
    {0, 1, 0},
    {1, 12, 20},
    {2, 14, 25},
    {3, 9, 12}
};
