#include <string>

#include "targetable.h"

using namespace std;

void Targetable::damage(int amount)
{
    health -= amount;
}