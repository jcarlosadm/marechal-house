#include <iostream>
#include <cube.h>

Cube::Cube()
{
    std::cout << "Cube" << std::endl;
}

void Cube::draw()
{
    std::cout << "Cube::draw" << std::endl;
}

Cube::~Cube() {
    std::cout << "destructin cube..." << std::endl;
}
