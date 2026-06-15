#ifndef TARGETABLE_H
#define TARGETABLE_H

#include <string>

using namespace std;

class Targetable
{
    public:
        string name;
        int health;

        void damage(int amount);
};

#endif