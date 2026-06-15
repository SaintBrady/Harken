#include <iostream>
#include <string>
#include <vector>

#include "container.h"
#include "item.h"
#include "weapon.h"
#include "player.h"
#include "npc.h"
#include "targetable.h"

using namespace std;

int main()
{
    Player player("Hero", 100);
    NPC npc("Orc", 100, Weapon("Gore Dagger"));
    Container chest(Container::CHEST);

    while (true)
    {
        cout << "-- Available Actions --\n1 - Spawn Chest\n2 - Open Inventory\n3 - Orc Swing\n4 - Player Swing\n5 - Exit" << endl;

        int input;
        string choice = "";
        bool validInput = true;

        getline(cin, choice);
        try
        {
            input = stoi(choice);
        }
        catch(exception e)
        {
            cout << "Invalid Input..." << endl;
            validInput = false;
        }

        if(validInput) {
            switch(input)
            {
                case 1:
                {
                    cout << "You see a chest. Do you want to open it? (y/n): ";
                    getline(cin, choice);

                    if(choice == "y" || choice == "Y")
                    {
                        chest.open(player, chest);
                    }
                    else if(choice == "n" || choice == "N")
                    {
                        cout << "You decide not to open the chest." << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                    }
                    
                }
                    break;
                case 2:
                    player.openInventory();
                    break;
                case 3:
                    npc.swing(player);
                    break;
                case 4:
                    player.attack(npc);
                    break;
                case 5:
                    return 0;
                default:
                    cout << "Invalid input." << endl;
            }
        }
    }

    return 0;
}