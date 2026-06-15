#include <string>
#include <map>

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
    {"Empty", 0},
    {"Gore Dagger", 1},
    {"Radiant Mace", 2}
};

int Weapon::weaponsTable[3][3] = {
    {0, 0, 0},
    {1, 12, 2},
    {2, 14, 25}
};
