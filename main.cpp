#include <iostream>

#include "container.h"
#include "weapon.h"
#include "player.h"
#include "npc.h"
#include "gamecontroller.h"
#include "vector3d.h"
#include "quaternion.h"

using namespace std;

const float PI = 3.14159265;

//g++ -o main.exe -I ./TransformComponents *.cpp TransformComponents/*.cpp
int main()
{
    GameController gc;
    Player player("Hero", 100);
    NPC npc("Orc", 100, Weapon("Gore Dagger"));
    Container chest(Container::CHEST);

    // Global axis rotation quaternions for testing
    Quaternion xQ(0.0, 1.0, 0.0, 0.0);
    Quaternion yQ(0.0, 0.0, 1.0, 0.0);
    Quaternion zQ(0.0, 0.0, 0.0, 1.0);
    
    while (true)
    {
        cout << "-- Available Actions --\n1 - Spawn Chest\n2 - Open Inventory\n3 - Orc Swing\n4 - Player Swing\n5 - Print Objects\n6 - Rotate Chest\n7 - Exit" << endl;

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
                    gc.envObjects.push_back(&chest);
                    gc.envObjects.push_back(&player);
                    gc.envObjects.push_back(&npc);
                    gc.printObjects();
                    break;
                case 6:
                    cout << "--Chest Points Before Rotation--" << endl;
                    chest.mesh.printPoints();

                    chest.transform.rotation.Rotate(chest.mesh, yQ, PI/6);
                    chest.transform.rotation.Rotate(chest.mesh, zQ, PI/4);

                    cout << endl << "--Chest Points After Rotation--" << endl;
                    chest.mesh.printPoints();

                    break;
                case 7:
                    return 0;
                default:
                    cout << "Invalid input..." << endl;
            }
        }
    }

    return 0;
}