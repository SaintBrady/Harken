#include "characterbase.h"

void CharacterBase::damage(int amount)
{
    health -= amount;
}

void CharacterBase::attack(CharacterBase& target)
{
    Weapon *weapon = this->weapon;
    int damage = weapon->damage;
    std::string critText = "";

    if (((float)rand() / (float)(RAND_MAX)) <= weapon->critRating)
    {
        critText = "It is a critical hit! ";
        damage *= 2;
    }

    target.damage(damage);
    printf("%s swings at %s for %d damage. %s\n%s has %d health remaining\n\n", name.c_str(), target.name.c_str(), damage, critText.c_str(), target.name.c_str(), target.health);
}