#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "item.h"
#include "weapon.h"
#include "targetable.h"
#include "player.h"

using namespace std;

Player::Player(string name, int health)
{
    this->name = name;
    this->health = health;
    weapon = Weapon("Empty");
}

void Player::openInventory()
{
    cout << "-- Inventory --" << endl;
    for (Item& item : inventory)
    {
        cout << item.name.c_str() << endl;
    }

    while(true)
    {
        cout << "Select item you would like to equip or done to exit: ";
        string choice;
        getline(cin >> ws, choice);

        if(choice == "done") return;

        for (Item& item : inventory)
        {
            // Push current weapon back to inventory, then equip selected and remove from inventory
            if (item.name == choice && item.equippable)
            {
                if(weapon.name != "Empty")
                {
                    inventory.push_back(weapon);
                }

                Weapon *wep = new Weapon(item.name.c_str());
                weapon = *wep;

                cout << item.name << " has been equipped." << endl;
                inventory.erase(find(inventory.begin(), inventory.end(), item));
                return;
            }
        }
        cout << "Item not found or is unequippable! ";
    }
}

void Player::attack(Targetable& target)
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