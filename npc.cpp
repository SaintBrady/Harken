#include "npc.h"

NPC::NPC(std::string name, int health, Weapon weapon)
{
    this->name = name;
    this->health = health;
    this->weapon = &weapon;
}