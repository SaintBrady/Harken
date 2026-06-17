#include <iostream>

#include "gameController.h"
#include "weapon.h"
#include "npc.h"

GameController::GameController(char c)
{
    Weapon *wep = new Weapon("Rusty Knife");
    envObjects.push_back(new Weapon("Gore Dagger"));
    envObjects.push_back(new NPC("Goblin", 60, *wep));
}

void GameController::PrintObjects()
{
    for (GameObject* g : envObjects)
    {
        std::cout << g->name << std::endl;
    }
}