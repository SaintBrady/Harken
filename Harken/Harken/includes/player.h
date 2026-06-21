#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "item.h"
#include "characterbase.h"

class Player : public CharacterBase
{
    public:
        Item** inventory;
        const int INVENTORY_SIZE = 15;

        Player(std::string name, float health);

        void openInventory();
};

#endif