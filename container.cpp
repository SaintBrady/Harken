#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "item.h"
#include "weapon.h"
#include "player.h"
#include "container.h"

using namespace std;

Container::Container(Type type)
{
    slots = type;
}

void Container::genRandItems(Container &container)
{
    string itemTable[6] = {"Gold Coin", "Health Potion", "Sword", "Shield", "Radiant Mace", "Gore Dagger"};
    int numItems = container.slots;

    Item items[numItems];
    srand(time(0));
    for(int i = 0; i < numItems; i++)
    {
        int index = rand() % size(itemTable);
        container.inventory.push_back(Item(itemTable[index]));
    }
}

void Container::open(Player& player, Container& container)
{
    genRandItems(container);

    cout << "You found the following items in the chest:" << endl;
    for (int i = 0; i <= slots; i++)
    {
        container.inventory.push_back(container.inventory.at(i));
        cout << "- " << container.inventory.at(i).name << endl;
    }

    cout << "Select item(s) to add to your inventory (enter the item name, all, or done to finish): ";
    string choice;
    getline(cin >> ws, choice);

    while (choice != "done")
    {
        if (choice == "all")
        {
            for (Item& item : inventory)
            {
                player.inventory.push_back(item);
            }
            cout << "All items added to your inventory." << endl;
            break;
        }
        else
        {
            bool found = false;
            for (Item& item : inventory)
            {
                cout << "Checking Item name \'" << item.name << "\' against choice \'" << choice << "\'.\n";
                if (item.name == choice)
                {
                    player.inventory.push_back(item);
                    cout << item.name << " added to your inventory." << endl;
                    inventory.erase(find(inventory.begin(), inventory.end(), item));
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Item not found in the chest. ";
        }
        cout << "Select another item or type 'done' to finish: ";
        getline(cin >> ws, choice);
    }
}