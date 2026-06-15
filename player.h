#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "item.h"
#include "weapon.h"
#include "targetable.h"

class Player : public Targetable
{
    public:
        std::vector<Item> inventory;
        Weapon weapon;

        Player(std::string name, int health);

        void openInventory();

        void attack(Targetable& target);
};

#endif