#ifndef STAIRS_H
#define STAIRS_H

#include "shape.h"

class Stairs : public Shape
{
public:
    Stairs();
    ~Stairs();

    void draw();
private:
    std::vector<Shape *> shapes;
};

#endif // STAIRS_H
