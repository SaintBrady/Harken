#include <string>
#include <iostream>

#include "characterbase.h"
#include "weapon.h"

using namespace std;

void CharacterBase::damage(int amount)
{
    health -= amount;
}

void CharacterBase::attack(CharacterBase& target)
{
    Weapon *weapon = this->weapon;
    int damage = weapon->damage;
    cout << "Base weapon damage of swing: " << damage << endl;
    if (((float)rand() / (float)(RAND_MAX)) <= weapon->critRating)
    {
        damage += weapon->damage;
    }

    target.damage(damage);
    printf("%s swings at %s for %d damage! %s has %d health left...\n\n", name.c_str(), target.name.c_str(), damage, target.name.c_str(), target.health);
}