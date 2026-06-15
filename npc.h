#ifndef NPC_H
#define NPC_H

#include "targetable.h"
#include "weapon.h"

class NPC : public Targetable
{
    public:
        Weapon weapon;
        NPC(string name, int health, Weapon weapon);

        void swing(Targetable& target);
};

#endif