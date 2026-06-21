#ifndef TARGETABLE_H
#define TARGETABLE_H

#include "weapon.h"

class CharacterBase : public GameObject
{
    public:
        float health;
        Weapon *weapon = new Weapon("Unarmed");

        void damage(float amount);
        void attack(CharacterBase& target);
};

#endif