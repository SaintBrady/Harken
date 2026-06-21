#include <iostream>
//#include <bits/stdc++.h>

#include "weapon.h"
#include "container.h"

using namespace std;

Container::Container(Type type)
{
    name = "Chest";
    slots = type;
    inventory = new Item*[15]();

    float points[8][3] = {
        {-1, -1, 0},
        {-1, 1, 0},
        {1, -1, 0},
        {1, 1, 0},
        {-1, -1, 1},
        {-1, 1, 1},
        {1, -1, 1},
        {1, 1, 1}
    };
    for(int i = 0; i < 8; i++)
    {
        mesh.points.push_back(new Vector3D(points[i][0], points[i][1], points[i][2]));
    }
}

void Container::genRandItems(Container &container)
{
    string itemTable[6] = {"Gold Coin", "Health Potion", "Arcane Crystal", "Lute", "Radiant Mace", "Gore Dagger"};
    srand((unsigned int)time(0));

    for(int i = 0; i < container.slots; i++)
    {
        int index = rand() % (sizeof(itemTable)/sizeof(*itemTable));
        
        if(index > 3) container.inventory[i] = new Weapon(itemTable[index]);
        else container.inventory[i] = new Item(itemTable[index]);
    }
}

void Container::open(Player& player)
{
    genRandItems(*this);

    cout << "You found the following items in the chest:" << endl;
    for (int i = 0; i < slots; i++)
    {
        cout << "- " << inventory[i]->name.c_str() << endl;
    }

    input_loop:
    cout << "Select item(s) to add to your inventory (enter the item name, all, or done to finish): ";

    string choice;
    getline(cin >> ws, choice);
    bool takeAll = (choice == "all");
    bool found = false;

    while (choice != "done")
    {
        for (int i = 0; i < slots; i++)
        {
            // If container slot has item, valid item or all selected, go through loop and add to inventory
            if (inventory[i] == NULL || ((inventory[i]->name != choice) && !takeAll)) continue;

            for(int j = 0; j < player.INVENTORY_SIZE; j++)
            {
                if(player.inventory[j] == NULL)
                {
                    player.inventory[j] = inventory[i];
                    inventory[i] = NULL;
                    found = true;

                    if(takeAll) break;
                    else
                    {
                        cout << player.inventory[j]->name << " added to your inventory." << endl;
                        goto input_loop;
                    }
                }
            }
        }
        if(!found)
        {
            cout << "Item not found in the chest." << endl;
            goto input_loop;
        }
        cout << "All items added to your inventory." << endl;
        return;
    }
}