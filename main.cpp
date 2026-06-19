#include <iostream>

#include "container.h"
#include "weapon.h"
#include "player.h"
#include "npc.h"
#include "gamecontroller.h"
#include "vector2d.h"

using namespace std;

int main()
{
    Player player("Hero", 100);
    NPC npc("Orc", 100, Weapon("Gore Dagger"));
    Container chest(Container::CHEST);

    GameController gc;

    while (true)
    {
        cout << "-- Available Actions --\n1 - Spawn Chest\n2 - Open Inventory\n3 - Orc Swing\n4 - Player Swing\n5 - Print Objects\n6 - Exit" << endl;

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
                    chest.open(player);
                    break;
                }
                    break;
                case 2:
                    player.openInventory();
                    break;
                case 3:
                    npc.attack(player);
                    break;
                case 4:
                    player.attack(npc);
                    break;
                case 5:
                    chest.position.setPosition(10.0, 13.0);
                    chest.position /= 3.0;
                    gc.envObjects.push_back(&chest);
                    gc.envObjects.push_back(&player);
                    gc.envObjects.push_back(&npc);
                    gc.printObjects();
                    break;
                case 6:
                    return 0;
                default:
                    cout << "Invalid input." << endl;
            }
        }
    }

    return 0;
}