#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "item.h"
#include "weapon.h"
#include "characterbase.h"

class Player : public CharacterBase
{
    public:
        Item** inventory;
        const int INVENTORY_SIZE = 15;

        Player(std::string name, int health);

        void openInventory();
};

#endif