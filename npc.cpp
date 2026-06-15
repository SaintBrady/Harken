#include <iostream>

#include "targetable.h"
#include "weapon.h"
#include "npc.h"

using namespace std;

NPC::NPC(string name, int health, Weapon weapon)
{
    this->name = name;
    this->health = health;
    this->weapon = weapon;
}

void NPC::swing(Targetable& target)
{
    int damage = weapon.damage;
    cout << "Base weapon damage of swing: " << damage << endl;
    if (((float)rand() / (float)(RAND_MAX)) <= weapon.critRating)
    {
        damage += weapon.damage;
    }

    target.damage(damage);
    printf("%s swings at %s for %d damage! %s has %d health left...\n\n", name.c_str(), target.name.c_str(), damage, target.name.c_str(), target.health);
}