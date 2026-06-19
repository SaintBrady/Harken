#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <map>

#include "item.h"

class Weapon : public Item
{
    public:
        float damage, critRating;

        Weapon(std::string name = "Unarmed");

    private:
        static std::map<std::string, int> weaponsAlias;
        static int weaponsTable[4][3];
};

#endif