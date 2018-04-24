#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "shape.h"
#include "square.h"

class Parallelepiped : public Shape
{
public:
    Parallelepiped(float width, float height, float length);
    ~Parallelepiped();

    void draw();
private:
    std::vector<Shape *> shapes;
};

#endif // PARALLELEPIPED_H
