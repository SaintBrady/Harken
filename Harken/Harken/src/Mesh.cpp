#include <iostream>
#include "mesh.h"

void Mesh::printPoints()
{
    for(Vector3D* point : points)
    {
        std::cout << *point << std::endl;
    }
}