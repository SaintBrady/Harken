#ifndef NPC_H
#define NPC_H

#include "characterbase.h"
#include "weapon.h"

class NPC : public CharacterBase
{
    public:
        NPC(std::string name, int health, Weapon weapon);
};

#endif