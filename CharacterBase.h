#ifndef TARGETABLE_H
#define TARGETABLE_H

#include "weapon.h"

class CharacterBase : public GameObject
{
    public:
        int health;
        Weapon *weapon = new Weapon("Unarmed");

        void damage(int amount);
        void attack(CharacterBase& target);
};

#endif