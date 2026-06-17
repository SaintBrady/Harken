#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <vector>
#include "GameObject.h"

class GameController
{
    public:
        std::vector<GameObject*> envObjects;

        GameController(char c);
        //void spawnEnemies();
        void PrintObjects();
};

#endif