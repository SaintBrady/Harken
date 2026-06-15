#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <map>

#include "item.h"

class Weapon : public Item
{
    public:
        float damage, critRating;

        Weapon(std::string name = "Empty");

    private:
        static std::map<string, int> weaponsAlias;
        static int weaponsTable[3][3];
};

#endif