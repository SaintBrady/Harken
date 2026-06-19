#include <iostream>

#include "gameController.h"
#include "weapon.h"
#include "npc.h"

GameController::GameController() {}

void GameController::printObjects()
{
    for (GameObject* g : envObjects)
    {
        std::cout << g->name << " located at " << g->transform.position << std::endl;
    }
}