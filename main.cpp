#include <iostream>

#include "container.h"
#include "weapon.h"
#include "player.h"
#include "npc.h"
#include "gamecontroller.h"
#include "vector3d.h"
#include "quaternion.h"

using namespace std;

int main()
{
    Player player("Hero", 100);
    NPC npc("Orc", 100, Weapon("Gore Dagger"));
    Container chest(Container::CHEST);
    Quaternion q1(0.0, 1.0, 1.0, 1.0);
    q1.Normalize();
    Quaternion up(0.0, 0.0, 0.0, 1.0);

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
                    chest.transform.position.setPosition(3.0, 0.0, 0.0);
                    player.transform.position.setPosition(2.0, 7.0, -5.0);
                    //chest.transform.position /= 3.0;
                    gc.envObjects.push_back(&chest);
                    gc.envObjects.push_back(&player);
                    gc.envObjects.push_back(&npc);
                    gc.printObjects();
                    break;
                case 6:
                    return 0;
                case 7:
                    //cout << "Q1: " << q1 << ", Q2: " << q2 << ", Q1*Q2: " << q1 * q2 << endl;
                    cout << "Chest rotation before: " << chest.transform.rotation << endl;
                
                    chest.transform.rotation = q1;
                    chest.transform.rotation.Rotate(up);
                    cout << "Chest rotation after: " << chest.transform.rotation << endl;
                    break;
                default:
                    cout << "Invalid input." << endl;
            }
        }
    }

    return 0;
}