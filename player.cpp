#include <iostream>
#include <string>

#include "weapon.h"
#include "player.h"

using namespace std;

Player::Player(string name, int health)
{
    this->name = name;
    this->health = health;
    inventory = new Item*[INVENTORY_SIZE]();
    this->transform.position.x = 15.0;
    this->transform.position.y = 10.0;
    this->transform.position.z = 2.0;
    mesh.points.push_back(new Vector3D(2.0, 3.0, 0.0));
}

void Player::openInventory()
{
    cout << "-- Inventory --" << endl;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if(inventory[i] == NULL) continue;
        cout << "- " << inventory[i]->name.c_str() << endl;
    }

    while(true)
    {
        cout << "Select item you would like to equip or done to exit: ";
        string choice;
        getline(cin >> ws, choice);

        if(choice == "done") return;

        for (int i = 0; i < INVENTORY_SIZE; i++)
        {
            if(inventory[i] == NULL) continue;
            Item item = *inventory[i];

            if (item.name == choice && item.equippable)
            {
                Weapon* wepPtr = weapon;
                weapon = static_cast<Weapon*>(inventory[i]);
                inventory[i] = wepPtr;
                cout << "Equipping " << weapon->name << " with damage value of " << weapon->damage << endl;
                return;
            }
        }
        cout << "Item not found or is unequippable! " << endl;
    }
}